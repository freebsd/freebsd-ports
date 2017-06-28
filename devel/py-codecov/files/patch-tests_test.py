# The following test cases fails because the .git directory is not included. 
# Remove them for now until the reported issue #100 is fixed.
# https://github.com/codecov/codecov-python/issues/100

--- tests/test.py.orig	2017-04-28 14:06:12 UTC
+++ tests/test.py
@@ -2,9 +2,9 @@ import os
 import sys
 import pickle
 import itertools
+import unittest
 from ddt import ddt, data
 from mock import patch, Mock
-import unittest2 as unittest
 
 import subprocess
 
@@ -134,21 +134,6 @@ class TestUploader(unittest.TestCase):
                 self.assertEqual(codecov.main(), None)
                 assert post.called and put.called
 
-    def test_send(self):
-        with patch('requests.post') as post:
-            with patch('requests.put') as put:
-                post.return_value = Mock(status_code=200, text='target\ns3')
-                put.return_value = Mock(status_code=200)
-                with open(self.filepath, 'w+') as f:
-                    f.write('coverage data')
-                res = self.run_cli(False, commit='a'*40, branch='master', token='<token>')
-                self.assertEqual(res['result'].strip(), 'target')
-                assert 'https://codecov.io/upload/v4?' in post.call_args[0][0]
-                assert 'commit=aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa' in post.call_args[0][0]
-                assert 'token=%3Ctoken%3E' in post.call_args[0][0]
-                assert 'branch=master' in post.call_args[0][0]
-                assert 'tests/test.py' in put.call_args[1]['data']
-
     def test_send_error(self):
         with patch('requests.post') as post:
             post.return_value = Mock(status_code=400, text='error')
@@ -181,18 +166,6 @@ class TestUploader(unittest.TestCase):
         res = self.run_cli(token='@'+self.token, commit='a', branch='b')
         self.assertIn('token=a', res['urlargs'])
 
-    def test_bowerrc(self):
-        with open(self.bowerrc, 'w+') as f:
-            f.write('{"directory": "tests"}')
-        with open(self.filepath, 'w+') as f:
-            f.write('coverage data')
-        try:
-            self.run_cli(**self.defaults)
-        except AssertionError as e:
-            self.assertEqual(str(e),  "No coverage report found")
-        else:
-            raise Exception("Did not raise AssertionError")
-
     def test_disable_search(self):
         self.fake_report()
         try:
@@ -246,33 +219,6 @@ class TestUploader(unittest.TestCase):
         else:
             raise Exception("Did not raise AssertionError")
 
-    def test_bowerrc_none(self):
-        with open(self.bowerrc, 'w+') as f:
-            f.write('{"other_key": "tests"}')
-        with open(self.filepath, 'w+') as f:
-            f.write('coverage data')
-        res = self.run_cli(**self.defaults)
-        self.assertIn('tests/test.py', res['reports'])
-
-    def test_discovers(self):
-        with open(self.jacoco, 'w+') as f:
-            f.write('<jacoco></jacoco>')
-        with open(self.filepath, 'w+') as f:
-            f.write('coverage data')
-        res = self.run_cli(**self.defaults)
-        self.assertIn('coverage.xml', res['reports'])
-        self.assertIn('coverage data', res['reports'])
-        self.assertIn('jacoco.xml', res['reports'])
-        self.assertIn('<jacoco></jacoco>', res['reports'])
-
-    def test_not_jacoco(self):
-        with open(self.filepath, 'w+') as f:
-            f.write('<data>')
-        res = self.run_cli(file='tests/coverage.xml', **self.defaults)
-        res = res['reports'].split('<<<<<< network\n')[1].splitlines()
-        self.assertEqual(res[0], '# path=tests/coverage.xml')
-        self.assertEqual(res[1], '<data>')
-
     def test_run_coverage(self):
         self.skipTest('Not sure how to pull off atm')
         with open(self.coverage, 'w+') as f:
@@ -339,23 +285,6 @@ class TestUploader(unittest.TestCase):
         self.assertEqual(res['query']['branch'], 'master')
         self.assertEqual(res['codecov'].token, 'token')
 
-    def test_ci_jenkins_blue_ocean(self):
-        self.set_env(JENKINS_URL='https://....',
-                     BUILD_URL='https://....',
-                     BRANCH_NAME='master',
-                     CHANGE_ID='1',
-                     BUILD_NUMBER='41',
-                     CODECOV_TOKEN='token')
-        self.fake_report()
-        res = self.run_cli()
-        self.assertEqual(res['query']['service'], 'jenkins')
-        self.assertEqual(res['query']['commit'], codecov.check_output(("git", "rev-parse", "HEAD")))
-        self.assertEqual(res['query']['build'], '41')
-        self.assertEqual(res['query']['build_url'], 'https://....')
-        self.assertEqual(res['query']['pr'], '1')
-        self.assertEqual(res['query']['branch'], 'master')
-        self.assertEqual(res['codecov'].token, 'token')
-
     def test_ci_travis(self):
         self.set_env(TRAVIS="true",
                      TRAVIS_BRANCH="master",
@@ -459,20 +388,6 @@ class TestUploader(unittest.TestCase):
         self.assertEqual(res['query']['build'], '10')
         self.assertEqual(res['query']['pr'], '10')
         self.assertEqual(res['query']['job'], 'default')
-        self.assertEqual(res['codecov'].token, 'token')
-
-    def test_ci_drone(self):
-        self.set_env(DRONE='true',
-                     DRONE_BUILD_NUMBER='10',
-                     DRONE_BRANCH='master',
-                     DRONE_BUILD_URL='https://drone.io/github/builds/1',
-                     CODECOV_TOKEN='token')
-        self.fake_report()
-        res = self.run_cli()
-        self.assertEqual(res['query']['service'], 'drone.io')
-        self.assertEqual(res['query']['commit'], codecov.check_output(("git", "rev-parse", "HEAD")))
-        self.assertEqual(res['query']['build'], '10')
-        self.assertEqual(res['query']['build_url'], 'https://drone.io/github/builds/1')
         self.assertEqual(res['codecov'].token, 'token')
 
     def test_ci_shippable(self):
