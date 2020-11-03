From ca6815115c79da62b845f479f0cdd765bdbfb700 Mon Sep 17 00:00:00 2001
From: Marco Hinz <mh.codebro@gmail.com>
Date: Thu, 8 Oct 2020 11:52:17 +0200
Subject: [PATCH] provider: update supported Python versions (#13070)

Python 3.9 was released, so we need to add support for the upcoming Python 3.10.
Python 3.5 and earlier reached their end-of-life.

PEP 478: Python 3.5  Release Schedule: https://www.python.org/dev/peps/pep-0478
PEP 596: Python 3.9  Release Schedule: https://www.python.org/dev/peps/pep-0596
PEP 619: Python 3.10 Release Schedule: https://www.python.org/dev/peps/pep-0619
--- runtime/autoload/provider/pythonx.vim.orig	2020-11-03 14:47:53 UTC
+++ runtime/autoload/provider/pythonx.vim
@@ -28,8 +28,8 @@ endfunction
 function! s:get_python_candidates(major_version) abort
   return {
         \ 2: ['python2', 'python2.7', 'python2.6', 'python'],
-        \ 3: ['python3', 'python3.7', 'python3.6', 'python3.5', 'python3.4', 'python3.3',
-        \     'python']
+        \ 3: ['python3', 'python3.10', 'python3.9', 'python3.8', 'python3.7',
+        \     'python3.6', 'python']
         \ }[a:major_version]
 endfunction
 
