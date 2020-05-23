--- pglogical_dependency.c.orig	2020-04-06 19:40:00 UTC
+++ pglogical_dependency.c
@@ -232,8 +232,6 @@ static void reportDependentObjects(const ObjectAddress
 					   DropBehavior behavior,
 					   int msglevel,
 					   const ObjectAddress *origObject);
-static void AcquireDeletionLock(const ObjectAddress *object, int flags);
-static void ReleaseDeletionLock(const ObjectAddress *object);
 static bool find_expr_references_walker(Node *node,
 							find_expr_references_context *context);
 static void eliminate_duplicate_dependencies(ObjectAddresses *addrs);
@@ -926,51 +924,6 @@ reportDependentObjects(const ObjectAddresses *targetOb
 
 	pfree(clientdetail.data);
 	pfree(logdetail.data);
-}
-
-/*
- * AcquireDeletionLock - acquire a suitable lock for deleting an object
- *
- * We use LockRelation for relations, LockDatabaseObject for everything
- * else.  Note that dependency.c is not concerned with deleting any kind of
- * shared-across-databases object, so we have no need for LockSharedObject.
- */
-static void
-AcquireDeletionLock(const ObjectAddress *object, int flags)
-{
-	if (object->classId == RelationRelationId)
-	{
-		/*
-		 * In DROP INDEX CONCURRENTLY, take only ShareUpdateExclusiveLock on
-		 * the index for the moment.  index_drop() will promote the lock once
-		 * it's safe to do so.  In all other cases we need full exclusive
-		 * lock.
-		 */
-		if (flags & PERFORM_DELETION_CONCURRENTLY)
-			LockRelationOid(object->objectId, ShareUpdateExclusiveLock);
-		else
-			LockRelationOid(object->objectId, AccessExclusiveLock);
-	}
-	else
-	{
-		/* assume we should lock the whole object not a sub-object */
-		LockDatabaseObject(object->classId, object->objectId, 0,
-						   AccessExclusiveLock);
-	}
-}
-
-/*
- * ReleaseDeletionLock - release an object deletion lock
- */
-static void
-ReleaseDeletionLock(const ObjectAddress *object)
-{
-	if (object->classId == RelationRelationId)
-		UnlockRelationOid(object->objectId, AccessExclusiveLock);
-	else
-		/* assume we should lock the whole object not a sub-object */
-		UnlockDatabaseObject(object->classId, object->objectId, 0,
-							 AccessExclusiveLock);
 }
 
 /*
