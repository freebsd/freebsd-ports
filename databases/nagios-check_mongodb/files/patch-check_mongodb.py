--- check_mongodb.py.orig	2014-03-10 20:01:19.000000000 +0400
+++ check_mongodb.py	2014-05-12 15:22:50.000000000 +0400
@@ -31,8 +31,8 @@ import os
 
 try:
     import pymongo
-except ImportError, e:
-    print e
+except ImportError as e:
+    print(e)
     sys.exit(2)
 
 # As of pymongo v 1.9 the SON API is part of the BSON package, therefore attempt
@@ -84,29 +84,29 @@ def numeric_type(param):
 def check_levels(param, warning, critical, message, ok=[]):
     if (numeric_type(critical) and numeric_type(warning)):
         if param >= critical:
-            print "CRITICAL - " + message
+            print("CRITICAL - " + message)
             sys.exit(2)
         elif param >= warning:
-            print "WARNING - " + message
+            print("WARNING - " + message)
             sys.exit(1)
         else:
-            print "OK - " + message
+            print("OK - " + message)
             sys.exit(0)
     else:
         if param in critical:
-            print "CRITICAL - " + message
+            print("CRITICAL - " + message)
             sys.exit(2)
 
         if param in warning:
-            print "WARNING - " + message
+            print("WARNING - " + message)
             sys.exit(1)
 
         if param in ok:
-            print "OK - " + message
+            print("OK - " + message)
             sys.exit(0)
 
         # unexpected param value
-        print "CRITICAL - Unexpected value : %d" % param + "; " + message
+        print("CRITICAL - Unexpected value : %d" % param + "; " + message)
         return 2
 
 
@@ -268,11 +268,11 @@ def mongo_connect(host=None, port=None, 
             db = con["admin"]
             if not db.authenticate(user, passwd):
                 sys.exit("Username/Password incorrect")
-    except Exception, e:
+    except Exception as e:
         if isinstance(e, pymongo.errors.AutoReconnect) and str(e).find(" is an arbiter") != -1:
             # We got a pymongo AutoReconnect exception that tells us we connected to an Arbiter Server
             # This means: Arbiter is reachable and can answer requests/votes - this is all we need to know from an arbiter
-            print "OK - State: 7 (Arbiter)"
+            print("OK - State: 7 (Arbiter)")
             sys.exit(0)
         return exit_with_general_critical(e), None
     return 0, con
@@ -282,7 +282,7 @@ def exit_with_general_warning(e):
     if isinstance(e, SystemExit):
         return e
     else:
-        print "WARNING - General MongoDB warning:", e
+        print("WARNING - General MongoDB warning:", e)
     return 1
 
 
@@ -290,7 +290,7 @@ def exit_with_general_critical(e):
     if isinstance(e, SystemExit):
         return e
     else:
-        print "CRITICAL - General MongoDB Error:", e
+        print("CRITICAL - General MongoDB Error:", e)
     return 2
 
 
@@ -324,7 +324,7 @@ def check_connections(con, warning, crit
                 (available, "available_connections")])
         return check_levels(used_percent, warning, critical, message)
 
-    except Exception, e:
+    except Exception as e:
         return exit_with_general_critical(e)
 
 
@@ -347,9 +347,9 @@ def check_rep_lag(con, host, port, warni
         # Get replica set status
         try:
             rs_status = con.admin.command("replSetGetStatus")
-        except pymongo.errors.OperationFailure, e:
+        except pymongo.errors.OperationFailure as e:
             if e.code == None and str(e).find('failed: not running with --replSet"'):
-                print "OK - Not running with replSet"
+                print("OK - Not running with replSet")
                 return 0
 
         serverVersion = tuple(con.server_info()['version'].split('.'))
@@ -376,19 +376,19 @@ def check_rep_lag(con, host, port, warni
 
             # Check if we're in the middle of an election and don't have a primary
             if primary_node is None:
-                print "WARNING - No primary defined. In an election?"
+                print("WARNING - No primary defined. In an election?")
                 return 1
 
             # Check if we failed to find the current host
             # below should never happen
             if host_node is None:
-                print "CRITICAL - Unable to find host '" + host + "' in replica set."
+                print("CRITICAL - Unable to find host '" + host + "' in replica set.")
                 return 2
 
             # Is the specified host the primary?
             if host_node["stateStr"] == "PRIMARY":
                 if max_lag == False:
-                    print "OK - This is the primary."
+                    print("OK - This is the primary.")
                     return 0
                 else:
                     #get the maximal replication lag
@@ -413,7 +413,7 @@ def check_rep_lag(con, host, port, warni
                         message += performance_data(perf_data, [(maximal_lag, "replication_lag", warning, critical)])
                     return check_levels(maximal_lag, warning, critical, message)
             elif host_node["stateStr"] == "ARBITER":
-                print "OK - This is an arbiter"
+                print("OK - This is an arbiter")
                 return 0
 
             # Find the difference in optime between current node and PRIMARY
@@ -465,12 +465,12 @@ def check_rep_lag(con, host, port, warni
 
             # Check if we're in the middle of an election and don't have a primary
             if primary_node is None:
-                print "WARNING - No primary defined. In an election?"
+                print("WARNING - No primary defined. In an election?")
                 sys.exit(1)
 
             # Is the specified host the primary?
             if host_node["stateStr"] == "PRIMARY":
-                print "OK - This is the primary."
+                print("OK - This is the primary.")
                 sys.exit(0)
 
             # Find the difference in optime between current node and PRIMARY
@@ -489,7 +489,7 @@ def check_rep_lag(con, host, port, warni
                 message += performance_data(perf_data, [(lag, "replication_lag", warning, critical)])
             return check_levels(lag, warning, critical, message)
 
-    except Exception, e:
+    except Exception as e:
         return exit_with_general_critical(e)
 
 
@@ -502,7 +502,7 @@ def check_memory(con, warning, critical,
     try:
         data = get_server_status(con)
         if not data['mem']['supported'] and not mapped_memory:
-            print "OK - Platform not supported for memory info"
+            print("OK - Platform not supported for memory info")
             return 0
         #
         # convert to gigs
@@ -539,7 +539,7 @@ def check_memory(con, warning, critical,
         else:
             return check_levels(mem_resident, warning, critical, message)
 
-    except Exception, e:
+    except Exception as e:
         return exit_with_general_critical(e)
 
 
@@ -552,7 +552,7 @@ def check_memory_mapped(con, warning, cr
     try:
         data = get_server_status(con)
         if not data['mem']['supported']:
-            print "OK - Platform not supported for memory info"
+            print("OK - Platform not supported for memory info")
             return 0
         #
         # convert to gigs
@@ -574,10 +574,10 @@ def check_memory_mapped(con, warning, cr
         if not mem_mapped == -1:
             return check_levels(mem_mapped, warning, critical, message)
         else:
-            print "OK - Server does not provide mem.mapped info"
+            print("OK - Server does not provide mem.mapped info")
             return 0
 
-    except Exception, e:
+    except Exception as e:
         return exit_with_general_critical(e)
 
 
@@ -594,7 +594,7 @@ def check_lock(con, warning, critical, p
         message += performance_data(perf_data, [("%.2f" % lock_percentage, "lock_percentage", warning, critical)])
         return check_levels(lock_percentage, warning, critical, message)
 
-    except Exception, e:
+    except Exception as e:
         return exit_with_general_critical(e)
 
 
@@ -619,7 +619,7 @@ def check_flushing(con, warning, critica
 
         return check_levels(flush_time, warning, critical, message)
 
-    except Exception, e:
+    except Exception as e:
         return exit_with_general_critical(e)
 
 
@@ -638,10 +638,10 @@ def index_miss_ratio(con, warning, criti
         except KeyError:
             not_supported_msg = "not supported on this platform"
             if data['indexCounters'].has_key('note'):
-                print "OK - MongoDB says: " + not_supported_msg
+                print("OK - MongoDB says: " + not_supported_msg)
                 return 0
             else:
-                print "WARNING - Can't get counter from MongoDB"
+                print("WARNING - Can't get counter from MongoDB")
                 return 1
 
         message = "Miss Ratio: %.2f" % miss_ratio
@@ -649,7 +649,7 @@ def index_miss_ratio(con, warning, criti
 
         return check_levels(miss_ratio, warning, critical, message)
 
-    except Exception, e:
+    except Exception as e:
         return exit_with_general_critical(e)
 
 
@@ -663,7 +663,7 @@ def check_replset_state(con, perf_data, 
     except:
         critical = [8, 4, -1]
 
-    ok = range(-1, 8)  # should include the range of all posiible values
+    ok = list(range(-1, 8))  # should include the range of all posiible values
     try:
         try:
             try:
@@ -672,7 +672,7 @@ def check_replset_state(con, perf_data, 
             except:
                 data = con.admin.command(son.SON([('replSetGetStatus', 1)]))
             state = int(data['myState'])
-        except pymongo.errors.OperationFailure, e:
+        except pymongo.errors.OperationFailure as e:
             if e.code == None and str(e).find('failed: not running with --replSet"'):
                 state = -1
 
@@ -698,7 +698,7 @@ def check_replset_state(con, perf_data, 
             message = "State: %i (Unknown state)" % state
         message += performance_data(perf_data, [(state, "state")])
         return check_levels(state, warning, critical, message, ok)
-    except Exception, e:
+    except Exception as e:
         return exit_with_general_critical(e)
 
 
@@ -714,7 +714,7 @@ def check_databases(con, warning, critic
         message = "Number of DBs: %.0f" % count
         message += performance_data(perf_data, [(count, "databases", warning, critical, message)])
         return check_levels(count, warning, critical, message)
-    except Exception, e:
+    except Exception as e:
         return exit_with_general_critical(e)
 
 
@@ -736,7 +736,7 @@ def check_collections(con, warning, crit
         message += performance_data(perf_data, [(count, "collections", warning, critical, message)])
         return check_levels(count, warning, critical, message)
 
-    except Exception, e:
+    except Exception as e:
         return exit_with_general_critical(e)
 
 
@@ -779,15 +779,15 @@ def check_database_size(con, database, w
             #perfdata += " database=%s" %(database)
 
         if storage_size >= critical:
-            print "CRITICAL - Database size: %.0f MB, Database: %s%s" % (storage_size, database, perfdata)
+            print("CRITICAL - Database size: %.0f MB, Database: %s%s" % (storage_size, database, perfdata))
             return 2
         elif storage_size >= warning:
-            print "WARNING - Database size: %.0f MB, Database: %s%s" % (storage_size, database, perfdata)
+            print("WARNING - Database size: %.0f MB, Database: %s%s" % (storage_size, database, perfdata))
             return 1
         else:
-            print "OK - Database size: %.0f MB, Database: %s%s" % (storage_size, database, perfdata)
+            print("OK - Database size: %.0f MB, Database: %s%s" % (storage_size, database, perfdata))
             return 0
-    except Exception, e:
+    except Exception as e:
         return exit_with_general_critical(e)
 
 
@@ -806,15 +806,15 @@ def check_database_indexes(con, database
             perfdata += " | database_indexes=%i;%i;%i" % (index_size, warning, critical)
 
         if index_size >= critical:
-            print "CRITICAL - %s indexSize: %.0f MB %s" % (database, index_size, perfdata)
+            print("CRITICAL - %s indexSize: %.0f MB %s" % (database, index_size, perfdata))
             return 2
         elif index_size >= warning:
-            print "WARNING - %s indexSize: %.0f MB %s" % (database, index_size, perfdata)
+            print("WARNING - %s indexSize: %.0f MB %s" % (database, index_size, perfdata))
             return 1
         else:
-            print "OK - %s indexSize: %.0f MB %s" % (database, index_size, perfdata)
+            print("OK - %s indexSize: %.0f MB %s" % (database, index_size, perfdata))
             return 0
-    except Exception, e:
+    except Exception as e:
         return exit_with_general_critical(e)
 
 
@@ -833,15 +833,15 @@ def check_collection_indexes(con, databa
             perfdata += " | collection_indexes=%i;%i;%i" % (total_index_size, warning, critical)
 
         if total_index_size >= critical:
-            print "CRITICAL - %s.%s totalIndexSize: %.0f MB %s" % (database, collection, total_index_size, perfdata)
+            print("CRITICAL - %s.%s totalIndexSize: %.0f MB %s" % (database, collection, total_index_size, perfdata))
             return 2
         elif total_index_size >= warning:
-            print "WARNING - %s.%s totalIndexSize: %.0f MB %s" % (database, collection, total_index_size, perfdata)
+            print("WARNING - %s.%s totalIndexSize: %.0f MB %s" % (database, collection, total_index_size, perfdata))
             return 1
         else:
-            print "OK - %s.%s totalIndexSize: %.0f MB %s" % (database, collection, total_index_size, perfdata)
+            print("OK - %s.%s totalIndexSize: %.0f MB %s" % (database, collection, total_index_size, perfdata))
             return 0
-    except Exception, e:
+    except Exception as e:
         return exit_with_general_critical(e)
 
 
@@ -858,7 +858,7 @@ def check_queues(con, warning, critical,
         message += performance_data(perf_data, [(total_queues, "total_queues", warning, critical), (readers_queues, "readers_queues"), (writers_queues, "writers_queues")])
         return check_levels(total_queues, warning, critical, message)
 
-    except Exception, e:
+    except Exception as e:
         return exit_with_general_critical(e)
 
 
@@ -905,7 +905,7 @@ def check_queries_per_second(con, query_
 
         return check_levels(query_per_sec, warning, critical, message)
 
-    except Exception, e:
+    except Exception as e:
         return exit_with_general_critical(e)
 
 
@@ -952,7 +952,7 @@ def check_oplog(con, warning, critical, 
         message += performance_data(perf_data, [("%.2f" % hours_in_oplog, 'oplog_time', warning, critical), ("%.2f " % approx_level, 'oplog_time_100_percent_used')])
         return check_levels(-approx_level, -warning, -critical, message)
 
-    except Exception, e:
+    except Exception as e:
         return exit_with_general_critical(e)
 
 
@@ -970,7 +970,7 @@ Under very high write situations it is n
         message += performance_data(perf_data, [(j_commits_in_wl, "j_commits_in_wl", warning, critical)])
         return check_levels(j_commits_in_wl, warning, critical, message)
 
-    except Exception, e:
+    except Exception as e:
         return exit_with_general_critical(e)
 
 
@@ -986,7 +986,7 @@ def check_journaled(con, warning, critic
         message += performance_data(perf_data, [("%.2f" % journaled, "journaled", warning, critical)])
         return check_levels(journaled, warning, critical, message)
 
-    except Exception, e:
+    except Exception as e:
         return exit_with_general_critical(e)
 
 
@@ -1003,7 +1003,7 @@ than the amount physically written to di
         message += performance_data(perf_data, [("%.2f" % writes, "write_to_data_files", warning, critical)])
         return check_levels(writes, warning, critical, message)
 
-    except Exception, e:
+    except Exception as e:
         return exit_with_general_critical(e)
 
 
@@ -1015,7 +1015,7 @@ def get_opcounters(data, opcounters_name
         delete = data[opcounters_name]['delete']
         getmore = data[opcounters_name]['getmore']
         command = data[opcounters_name]['command']
-    except KeyError, e:
+    except KeyError as e:
         return 0, [0] * 100
     total_commands = insert + query + update + delete + getmore + command
     new_vals = [total_commands, insert, query, update, delete, getmore, command]
@@ -1181,7 +1181,7 @@ def check_page_faults(con, sample_time, 
             #on linux servers only
             page_faults = (int(data2['extra_info']['page_faults']) - int(data1['extra_info']['page_faults'])) / sample_time
         except KeyError:
-            print "WARNING - Can't get extra_info.page_faults counter from MongoDB"
+            print("WARNING - Can't get extra_info.page_faults counter from MongoDB")
             sys.exit(1)
 
         message = "Page Faults: %i" % (page_faults)
@@ -1189,7 +1189,7 @@ def check_page_faults(con, sample_time, 
         message += performance_data(perf_data, [(page_faults, "page_faults", warning, critical)])
         check_levels(page_faults, warning, critical, message)
 
-    except Exception, e:
+    except Exception as e:
         exit_with_general_critical(e)
 
 
@@ -1205,11 +1205,11 @@ def chunks_balance(con, database, collec
             shards = col.distinct("shard")
 
         except:
-            print "WARNING - Can't get chunks infos from MongoDB"
+            print("WARNING - Can't get chunks infos from MongoDB")
             sys.exit(1)
 
         if nscount == 0:
-            print "WARNING - Namespace %s is not sharded" % (nsfilter)
+            print("WARNING - Namespace %s is not sharded" % (nsfilter))
             sys.exit(1)
 
         avgchunksnb = nscount / len(shards)
@@ -1221,19 +1221,19 @@ def chunks_balance(con, database, collec
             message = "Namespace: %s, Shard name: %s, Chunk delta: %i" % (nsfilter, shard, delta)
 
             if delta >= criticalnb and delta > 0:
-                print "CRITICAL - Chunks not well balanced " + message
+                print("CRITICAL - Chunks not well balanced " + message)
                 sys.exit(2)
             elif delta >= warningnb  and delta > 0:
-                print "WARNING - Chunks not well balanced  " + message
+                print("WARNING - Chunks not well balanced  " + message)
                 sys.exit(1)
 
-        print "OK - Chunks well balanced across shards"
+        print("OK - Chunks well balanced across shards")
         sys.exit(0)
 
-    except Exception, e:
+    except Exception as e:
         exit_with_general_critical(e)
 
-    print "OK - Chunks well balanced across shards"
+    print("OK - Chunks well balanced across shards")
     sys.exit(0)
 
 
@@ -1249,7 +1249,7 @@ def check_connect_primary(con, warning, 
             data = con.admin.command(son.SON([('isMaster', 1)]))
 
         if data['ismaster'] == True:
-            print "OK - This server is primary"
+            print("OK - This server is primary")
             return 0
 
         phost = data['primary'].split(':')[0]
@@ -1267,17 +1267,17 @@ def check_connect_primary(con, warning, 
 
         return check_levels(pconn_time, warning, critical, message)
 
-    except Exception, e:
+    except Exception as e:
         return exit_with_general_critical(e)
 
 
 def check_collection_state(con, database, collection):
     try:
         con[database][collection].find_one()
-        print "OK - Collection %s.%s is reachable " % (database, collection)
+        print("OK - Collection %s.%s is reachable " % (database, collection))
         return 0
 
-    except Exception, e:
+    except Exception as e:
         return exit_with_general_critical(e)
 
 
@@ -1289,7 +1289,7 @@ def check_row_count(con, database, colle
 
         return check_levels(count, warning, critical, message)
 
-    except Exception, e:
+    except Exception as e:
         return exit_with_general_critical(e)
 
 
@@ -1309,7 +1309,7 @@ def write_values(file_name, string):
     f = None
     try:
         f = open(file_name, 'w')
-    except IOError, e:
+    except IOError as e:
         #try creating
         if (e.errno == 2):
             ensure_dir(file_name)
@@ -1328,11 +1328,11 @@ def read_values(file_name):
         data = f.read()
         f.close()
         return 0, data
-    except IOError, e:
+    except IOError as e:
         if (e.errno == 2):
             #no previous data
             return 1, ''
-    except Exception, e:
+    except Exception as e:
         return 2, None
 
 
