--- DNS/tests/test_base.py.orig	2014-04-25 01:41:55 UTC
+++ DNS/tests/test_base.py
@@ -33,12 +33,12 @@ class TestBase(unittest.TestCase):
         self.assertTrue(a_response.answers)
         # is the result vaguely ipv4 like?
         self.assertEqual(a_response.answers[0]['data'].count('.'), 3)
-        self.assertEqual(a_response.answers[0]['data'],'93.184.216.119')
+        self.assertEqual(a_response.answers[0]['data'],'93.184.216.34')
 
         # Default result type for .qry object is an ipaddress object
         ad_response = dnsobj.qry(qtype='A')
         self.assertTrue(ad_response.answers)
-        self.assertEqual(ad_response.answers[0]['data'],ipaddress.IPv4Address('93.184.216.119'))
+        self.assertEqual(ad_response.answers[0]['data'],ipaddress.IPv4Address('93.184.216.34'))
 
         ab_response = dnsobj.qry(qtype='A', resulttype='binary')
         self.assertTrue(ab_response.answers)
@@ -46,11 +46,11 @@ class TestBase(unittest.TestCase):
         self.assertEqual(len(ab_response.answers[0]['data']), 4)
         for b in ab_response.answers[0]['data']:
             assertIsByte(b)
-        self.assertEqual(ab_response.answers[0]['data'],b']\xb8\xd8w')
+        self.assertEqual(ab_response.answers[0]['data'],b']\xb8\xd8"')
 
         ai_response = dnsobj.qry(qtype='A', resulttype='integer')
         self.assertTrue(ai_response.answers)
-        self.assertEqual(ai_response.answers[0]['data'],1572395127)
+        self.assertEqual(ai_response.answers[0]['data'],1572395042)
 
 
     def testDnsRequestAAAA(self):
@@ -61,12 +61,12 @@ class TestBase(unittest.TestCase):
         self.assertTrue(aaaa_response.answers)
         # does the result look like an ipv6 address?
         self.assertTrue(':' in aaaa_response.answers[0]['data'])
-        self.assertEqual(aaaa_response.answers[0]['data'],'2606:2800:220:6d:26bf:1447:1097:aa7')
+        self.assertEqual(aaaa_response.answers[0]['data'],'2606:2800:220:1:248:1893:25c8:1946')
 
         # default is returning ipaddress object
         aaaad_response = dnsobj.qry(qtype='AAAA')
         self.assertTrue(aaaad_response.answers)
-        self.assertEqual(aaaad_response.answers[0]['data'],ipaddress.IPv6Address('2606:2800:220:6d:26bf:1447:1097:aa7'))
+        self.assertEqual(aaaad_response.answers[0]['data'],ipaddress.IPv6Address('2606:2800:220:1:248:1893:25c8:1946'))
         
         aaaab_response = dnsobj.qry(qtype='AAAA', resulttype='binary')
         self.assertTrue(aaaab_response.answers)
@@ -74,11 +74,11 @@ class TestBase(unittest.TestCase):
         self.assertEqual(len(aaaab_response.answers[0]['data']) , 16)
         for b in aaaab_response.answers[0]['data']:
             assertIsByte(b)
-        self.assertEqual(aaaab_response.answers[0]['data'],b'&\x06(\x00\x02 \x00m&\xbf\x14G\x10\x97\n\xa7')
+        self.assertEqual(aaaab_response.answers[0]['data'],b'&\x06(\x00\x02 \x00\x01\x02H\x18\x93%\xc8\x19F')
         # IPv6 decimal
         aaaai_response = dnsobj.qry(qtype='AAAA', resulttype='integer')
         self.assertTrue(aaaai_response.answers)
-        self.assertEqual(aaaai_response.answers[0]['data'], 50542628918019815862290244053507705511)
+        self.assertEqual(aaaai_response.answers[0]['data'], 50542628918019813867414319910101719366)
 
     def testDnsRequestEmptyMX(self):
         dnsobj = DNS.DnsRequest('example.org')
@@ -168,7 +168,7 @@ class TestBase(unittest.TestCase):
         self.assertTrue(ad_response.answers)
         # is the result vaguely ipv4 like?
         self.assertEqual(ad_response.answers[0]['data'].count('.'), 3)
-        self.assertEqual(ad_response.answers[0]['data'],'93.184.216.119')
+        self.assertEqual(ad_response.answers[0]['data'],'93.184.216.34')
 
     def testDnsRequestAAAAD(self):
         dnsob = DNS.DnsRequest('example.org')
@@ -180,7 +180,7 @@ class TestBase(unittest.TestCase):
         self.assertEqual(len(aaaad_response.answers[0]['data']) , 16)
         for b in aaaad_response.answers[0]['data']:
             assertIsByte(b)
-        self.assertEqual(aaaad_response.answers[0]['data'],b'&\x06(\x00\x02 \x00m&\xbf\x14G\x10\x97\n\xa7')
+        self.assertEqual(aaaad_response.answers[0]['data'],b'&\x06(\x00\x02 \x00\x01\x02H\x18\x93%\xc8\x19F')
         
     def testDnsRequestEmptyMXD(self):
         dnsob = DNS.DnsRequest('example.org')
