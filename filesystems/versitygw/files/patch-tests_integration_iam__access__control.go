--- tests/integration/iam_access_control.go.orig	2026-10-11 12:06:36 UTC
+++ tests/integration/iam_access_control.go
@@ -1716,7 +1716,7 @@ func IAMAccessControl_TrustPolicyFederatedExactMatchAl
 		}
 		defer cleanup()
 
-		token := mustToken(map[string]any{"iss": providerURL, "aud": defaultTestAudience[0], "sub": "user1", "exp": 9999999999})
+		token := mustToken(map[string]any{"iss": providerURL, "aud": defaultTestAudience[0], "sub": "user1", "exp": int64(9999999999)})
 		return wantTrustAllowed(s, roleArn, token)
 	})
 }
@@ -1745,7 +1745,7 @@ func IAMAccessControl_TrustPolicyFederatedWrongProvide
 		}
 		defer deleteOIDCProvider(root, otherProviderArn)
 
-		token := mustToken(map[string]any{"iss": otherProviderURL, "aud": defaultTestAudience[0], "sub": "user1", "exp": 9999999999})
+		token := mustToken(map[string]any{"iss": otherProviderURL, "aud": defaultTestAudience[0], "sub": "user1", "exp": int64(9999999999)})
 		return wantTrustDeniedInvalidClaims(s, roleArn, token)
 	})
 }
@@ -1774,7 +1774,7 @@ func IAMAccessControl_TrustPolicyFederatedArrayMatches
 		defer cleanupRole()
 
 		// A token from the *second* array entry (not the first) still matches.
-		token := mustToken(map[string]any{"iss": secondURL, "aud": defaultTestAudience[0], "sub": "user1", "exp": 9999999999})
+		token := mustToken(map[string]any{"iss": secondURL, "aud": defaultTestAudience[0], "sub": "user1", "exp": int64(9999999999)})
 		return wantTrustAllowed(s, roleArn, token)
 	})
 }
@@ -1810,7 +1810,7 @@ func IAMAccessControl_TrustPolicyNonFederatedPrincipal
 				defer deleteIAMRole(root, roleName)
 
 				roleArn := "arn:aws:iam::" + testAccountID + ":role/" + roleName
-				token := mustToken(map[string]any{"iss": "https://unused.example.com", "aud": "client1", "sub": "user1", "exp": 9999999999})
+				token := mustToken(map[string]any{"iss": "https://unused.example.com", "aud": "client1", "sub": "user1", "exp": int64(9999999999)})
 				return wantTrustDeniedNoPrincipal(s, roleArn, token)
 			}(); err != nil {
 				return fmt.Errorf("%s: %w", tc.name, err)
@@ -1838,7 +1838,7 @@ func IAMAccessControl_TrustPolicyStringEqualsSubjectEx
 		}
 		defer cleanup()
 
-		token := mustToken(map[string]any{"iss": providerURL, "aud": defaultTestAudience[0], "exp": 9999999999, "sub": "repo:my-org/my-repo:ref:refs/heads/main"})
+		token := mustToken(map[string]any{"iss": providerURL, "aud": defaultTestAudience[0], "exp": int64(9999999999), "sub": "repo:my-org/my-repo:ref:refs/heads/main"})
 		return wantTrustAllowed(s, roleArn, token)
 	})
 }
@@ -1861,7 +1861,7 @@ func IAMAccessControl_TrustPolicyStringEqualsSubjectMi
 		}
 		defer cleanup()
 
-		token := mustToken(map[string]any{"iss": providerURL, "aud": defaultTestAudience[0], "exp": 9999999999, "sub": "repo:my-org/other-repo:ref:refs/heads/main"})
+		token := mustToken(map[string]any{"iss": providerURL, "aud": defaultTestAudience[0], "exp": int64(9999999999), "sub": "repo:my-org/other-repo:ref:refs/heads/main"})
 		return wantTrustDeniedInvalidClaims(s, roleArn, token)
 	})
 }
@@ -1884,7 +1884,7 @@ func IAMAccessControl_TrustPolicyStringLikeBranchWildc
 		}
 		defer cleanup()
 
-		token := mustToken(map[string]any{"iss": providerURL, "aud": defaultTestAudience[0], "exp": 9999999999, "sub": "repo:my-org/my-repo:ref:refs/heads/feature-x"})
+		token := mustToken(map[string]any{"iss": providerURL, "aud": defaultTestAudience[0], "exp": int64(9999999999), "sub": "repo:my-org/my-repo:ref:refs/heads/feature-x"})
 		return wantTrustAllowed(s, roleArn, token)
 	})
 }
@@ -1908,7 +1908,7 @@ func IAMAccessControl_TrustPolicyStringLikeTagSubjectD
 		}
 		defer cleanup()
 
-		token := mustToken(map[string]any{"iss": providerURL, "aud": defaultTestAudience[0], "exp": 9999999999, "sub": "repo:my-org/my-repo:pull_request"})
+		token := mustToken(map[string]any{"iss": providerURL, "aud": defaultTestAudience[0], "exp": int64(9999999999), "sub": "repo:my-org/my-repo:pull_request"})
 		return wantTrustDeniedInvalidClaims(s, roleArn, token)
 	})
 }
@@ -1935,7 +1935,7 @@ func IAMAccessControl_TrustPolicyAudienceCorrectAllowe
 		}
 		defer cleanup()
 
-		token := mustToken(map[string]any{"iss": providerURL, "aud": "expected-aud", "sub": "user1", "exp": 9999999999})
+		token := mustToken(map[string]any{"iss": providerURL, "aud": "expected-aud", "sub": "user1", "exp": int64(9999999999)})
 		return wantTrustAllowed(s, roleArn, token)
 	})
 }
@@ -1958,7 +1958,7 @@ func IAMAccessControl_TrustPolicyAudienceIncorrectDeni
 		}
 		defer cleanup()
 
-		token := mustToken(map[string]any{"iss": providerURL, "aud": "other-aud", "sub": "user1", "exp": 9999999999})
+		token := mustToken(map[string]any{"iss": providerURL, "aud": "other-aud", "sub": "user1", "exp": int64(9999999999)})
 		return wantTrustDeniedInvalidClaims(s, roleArn, token)
 	})
 }
@@ -1981,7 +1981,7 @@ func IAMAccessControl_TrustPolicyMultipleAudiencesArra
 		}
 		defer cleanup()
 
-		token := mustToken(map[string]any{"iss": providerURL, "aud": "aud-two", "sub": "user1", "exp": 9999999999})
+		token := mustToken(map[string]any{"iss": providerURL, "aud": "aud-two", "sub": "user1", "exp": int64(9999999999)})
 		return wantTrustAllowed(s, roleArn, token)
 	})
 }
@@ -2018,7 +2018,7 @@ func IAMAccessControl_TrustPolicyAudienceAndSubjectBot
 				}
 				defer cleanup()
 
-				token := mustToken(map[string]any{"iss": providerURL, "aud": tc.aud, "sub": tc.sub, "exp": 9999999999})
+				token := mustToken(map[string]any{"iss": providerURL, "aud": tc.aud, "sub": tc.sub, "exp": int64(9999999999)})
 				if tc.wantAllowed {
 					return wantTrustAllowed(s, roleArn, token)
 				}
@@ -2052,12 +2052,12 @@ func IAMAccessControl_TrustPolicyExplicitDenyStatement
 		}
 		defer cleanup()
 
-		blockedToken := mustToken(map[string]any{"iss": providerURL, "aud": defaultTestAudience[0], "sub": "blocked-user", "exp": 9999999999})
+		blockedToken := mustToken(map[string]any{"iss": providerURL, "aud": defaultTestAudience[0], "sub": "blocked-user", "exp": int64(9999999999)})
 		if err := wantTrustDeniedExplicit(s, roleArn, blockedToken); err != nil {
 			return fmt.Errorf("blocked subject: %w", err)
 		}
 
-		allowedToken := mustToken(map[string]any{"iss": providerURL, "aud": defaultTestAudience[0], "sub": "someone-else", "exp": 9999999999})
+		allowedToken := mustToken(map[string]any{"iss": providerURL, "aud": defaultTestAudience[0], "sub": "someone-else", "exp": int64(9999999999)})
 		if err := wantTrustAllowed(s, roleArn, allowedToken); err != nil {
 			return fmt.Errorf("non-blocked subject: %w", err)
 		}
@@ -2091,7 +2091,7 @@ func IAMAccessControl_TrustPolicyMultipleStatementsSec
 		}
 		defer cleanup()
 
-		token := mustToken(map[string]any{"iss": providerURL, "aud": defaultTestAudience[0], "sub": "user1", "exp": 9999999999})
+		token := mustToken(map[string]any{"iss": providerURL, "aud": defaultTestAudience[0], "sub": "user1", "exp": int64(9999999999)})
 		return wantTrustAllowed(s, roleArn, token)
 	})
 }
@@ -2117,7 +2117,7 @@ func IAMAccessControl_TrustPolicyMissingRequiredClaimD
 		defer cleanup()
 
 		// The token never includes an employee_id claim at all.
-		token := mustToken(map[string]any{"iss": providerURL, "aud": defaultTestAudience[0], "sub": "user1", "exp": 9999999999})
+		token := mustToken(map[string]any{"iss": providerURL, "aud": defaultTestAudience[0], "sub": "user1", "exp": int64(9999999999)})
 		return wantTrustDeniedInvalidClaims(s, roleArn, token)
 	})
 }
@@ -2289,7 +2289,7 @@ func IAMAccessControl_RolePermissionPolicyDoesNotAffec
 				}
 				defer cleanup()
 
-				token := mustToken(map[string]any{"iss": providerURL, "aud": defaultTestAudience[0], "sub": "user1", "exp": 9999999999})
+				token := mustToken(map[string]any{"iss": providerURL, "aud": defaultTestAudience[0], "sub": "user1", "exp": int64(9999999999)})
 				return wantTrustAllowed(s, roleArn, token)
 			}(); err != nil {
 				return fmt.Errorf("%s: %w", tc.name, err)
@@ -2320,7 +2320,7 @@ func IAMAccessControl_RoleTrustDenialIndependentOfPerm
 
 		// A different subject: trust Condition fails despite the role's own
 		// permission policy granting everything.
-		token := mustToken(map[string]any{"iss": "https://unused-in-this-assertion.example.com", "aud": defaultTestAudience[0], "sub": "someone-else", "exp": 9999999999})
+		token := mustToken(map[string]any{"iss": "https://unused-in-this-assertion.example.com", "aud": defaultTestAudience[0], "sub": "someone-else", "exp": int64(9999999999)})
 		return wantTrustDeniedInvalidClaims(s, roleArn, token)
 	})
 }
@@ -2348,7 +2348,7 @@ func IAMAccessControl_CrossIdentity_UnrelatedRoleCanno
 		}
 		defer cleanupB()
 
-		tokenForA := mustToken(map[string]any{"iss": providerAURL, "aud": defaultTestAudience[0], "sub": "user1", "exp": 9999999999})
+		tokenForA := mustToken(map[string]any{"iss": providerAURL, "aud": defaultTestAudience[0], "sub": "user1", "exp": int64(9999999999)})
 
 		if err := wantTrustAllowed(s, roleAArn, tokenForA); err != nil {
 			return fmt.Errorf("token still assumes its own role: %w", err)
@@ -2385,7 +2385,7 @@ func IAMAccessControl_CrossIdentity_AssumeRoleWithWebI
 		}
 		defer cleanup()
 
-		token := mustToken(map[string]any{"iss": providerURL, "aud": defaultTestAudience[0], "sub": "user1", "exp": 9999999999})
+		token := mustToken(map[string]any{"iss": providerURL, "aud": defaultTestAudience[0], "sub": "user1", "exp": int64(9999999999)})
 
 		if err := wantTrustAllowed(s, roleArn, token); err != nil {
 			return fmt.Errorf("signed with the real root credential: %w", err)
@@ -2805,7 +2805,7 @@ func runFederatedConditionCases(root *iam.Client, s *S
 			}
 			defer cleanup()
 
-			claims := map[string]any{"iss": providerURL, "aud": defaultTestAudience[0], "sub": "user1", "exp": 9999999999}
+			claims := map[string]any{"iss": providerURL, "aud": defaultTestAudience[0], "sub": "user1", "exp": int64(9999999999)}
 			for k, v := range tc.claims {
 				claims[k] = v
 			}
