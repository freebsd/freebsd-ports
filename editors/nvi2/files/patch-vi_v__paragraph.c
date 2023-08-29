From 517d821de7939f74a74bb6a553df0fff425fdead Mon Sep 17 00:00:00 2001
From: Zhihao Yuan <lichray@gmail.com>
Date: Tue, 29 Aug 2023 03:50:08 -0500
Subject: [PATCH] Treat consecutive paragraph indicators as different
 paragraphs (#119)

Consecutive empty lines count toward the same state, so there're
2x states (to get in and out). ^L and .PP are counted as text,
hitting those in the text should be treated as getting out of a
paragraph and then getting in.

Closes: #118
See also: https://marc.info/?l=openbsd-bugs&m=169100763926909&w=2
---
 vi/v_paragraph.c | 11 ++++++++---
 1 file changed, 8 insertions(+), 3 deletions(-)

diff --git a/vi/v_paragraph.c b/vi/v_paragraph.c
index abe8d9cf..2d7f0756 100644
--- vi/v_paragraph.c.orig	2020-08-01 22:27:51 UTC
+++ vi/v_paragraph.c
@@ -39,15 +39,20 @@
 	if (p[0] == '\014') {						\
 		if (!--cnt)						\
 			goto found;					\
+		if (pstate == P_INTEXT && !--cnt)			\
+			goto found;					\
 		continue;						\
 	}								\
 	if (p[0] != '.' || len < 2)					\
 		continue;						\
 	for (lp = VIP(sp)->ps; *lp != '\0'; lp += 2)			\
 		if (lp[0] == p[1] &&					\
-		    (lp[1] == ' ' && len == 2 || lp[1] == p[2]) &&	\
-		    !--cnt)						\
-			goto found;					\
+		    (lp[1] == ' ' && len == 2 || lp[1] == p[2])) {	\
+			if (!--cnt)					\
+				goto found;				\
+			if (pstate == P_INTEXT && !--cnt)		\
+				goto found;				\
+		}							\
 }
 
 /*
