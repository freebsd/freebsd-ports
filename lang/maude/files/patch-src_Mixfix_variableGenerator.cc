kind::IFF was removed in CVC4 1.6 
--- src/Mixfix/variableGenerator.cc.orig	2018-09-17 10:44:35 UTC
+++ src/Mixfix/variableGenerator.cc
@@ -312,18 +312,7 @@ VariableGenerator::dagToCVC4(DagNode* dag)
 	  //
 	case SMT_Symbol::EQUALS:
 	  {
-	    //
-	    //	Bizarrely CVC4 requires the IFF be used for Boolean equality so we need to
-	    //	check the SMT type associated with our first argument sort to catch this case.
-	    //
-	    Sort* domainSort = s->getOpDeclarations()[0].getDomainAndRange()[0];
-	    SMT_Info::SMT_Type smtType = smtInfo.getType(domainSort);
-	    if (smtType == SMT_Info::NOT_SMT)
-	      {
-		IssueWarning("term " << QUOTE(dag) << " does not belong to an SMT sort.");
-		goto fail;
-	      }
-	    return exprManager->mkExpr(((smtType == SMT_Info::BOOLEAN) ? kind::IFF : kind::EQUAL), exprs[0], exprs[1]);
+	    return exprManager->mkExpr(kind::EQUAL, exprs[0], exprs[1]);
 	  }
 	case SMT_Symbol::NOT_EQUALS:
 	  {
