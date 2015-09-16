--- phabricator/tests.py.orig	2013-11-23 04:51:16 UTC
+++ phabricator/tests.py
@@ -9,6 +9,9 @@ RESPONSES = {
     'maniphest.find': '{"result":{"PHID-TASK-4cgpskv6zzys6rp5rvrc":{"id":"722","phid":"PHID-TASK-4cgpskv6zzys6rp5rvrc","authorPHID":"PHID-USER-5022a9389121884ab9db","ownerPHID":"PHID-USER-5022a9389121884ab9db","ccPHIDs":["PHID-USER-5022a9389121884ab9db","PHID-USER-ba8aeea1b3fe2853d6bb"],"status":"3","priority":"Needs Triage","title":"Relations should be two-way","description":"When adding a differential revision you can specify Maniphest Tickets to add the relation. However, this doesnt add the relation from the ticket -> the differently.(This was added via the commit message)","projectPHIDs":["PHID-PROJ-358dbc2e601f7e619232","PHID-PROJ-f58a9ac58c333f106a69"],"uri":"https:\/\/secure.phabricator.com\/T722","auxiliary":[],"objectName":"T722","dateCreated":"1325553508","dateModified":"1325618490"}},"error_code":null,"error_info":null}'
 }
 
+# Protect against local user's .arcrc interference.
+phabricator.ARCRC = {}
+
 class PhabricatorTest(unittest.TestCase):
     def setUp(self):
         self.api = phabricator.Phabricator(username='test', certificate='test', host='http://localhost')
