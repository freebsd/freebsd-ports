# New ports collection makefile for:	php4-horde
# Date created:		11 September 2003
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

CATEGORIES=	lang www
PKGNAMESUFFIX=	-horde

MAINTAINER=	thierry@pompo.net
COMMENT=	A default PHP configured for the Horde framework

#-----------------------------------------------------------------------
# You may define these options:
#
# - WITHOUT_MYSQL:	this port is built with MySQL by default
#			but you might choose any other database
#			supported by PHP (e.g. WITH_POSTGRESQL).
#
# - WITHOUT_IMP:	this port is intended to build a default
#			package for IMP; use this knob if for
#			example you only need Chora.
#
# - WITHOUT_LDAP:	if you do not need OpenLDAP.
#
# - WITHOUT_MCAL:	if you don't plan to install Kronolith.
#
# - WITHOUT_FTP:	if you don't plan to install Gollem.
#
#-----------------------------------------------------------------------

WITH_DOMXML=	yes
WITH_GETTEXT=	yes
WITH_SESSION=	yes
.if !defined(NOCRYPT)
WITH_MCRYPT=	yes
.endif
.if !defined(WITHOUT_MYSQL)
WITH_MYSQL=	yes
.endif
.if !defined(WITHOUT_LDAP)
WITH_OPENLDAP=	yes
.endif
.if !defined(WITHOUT_IMP)
WITH_IMAP=	yes
.endif
.if !defined(WITHOUT_MCAL)
WITH_MCAL=	yes
.endif
.if !defined(WITHOUT_FTP)
WITH_FTP=	yes
.endif

MASTERDIR=	${.CURDIR}/../../lang/php4

.include "${MASTERDIR}/Makefile"
