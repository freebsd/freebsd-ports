# Ports collection makefile for:  pear-DB_ldap2
# Date created:			  26 March 2008
# Whom:				  Wen heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	DB_ldap2
PORTVERSION=	0.5.0
CATEGORIES=	databases net pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR DB compliant interface to LDAP v2 and v3 database

BUILD_DEPENDS=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	DB
FILES=		ldap2.php ldap3.php

TESTS=		errors.inc  prepexe.inc fetchmode_object.inc \
		sequences.inc  fetchmodes.inc   limit.inc \
		simplequery.inc  fetchrow.inc numrows.inc \
		ldap2/01connect.phpt   ldap2/101errormap_old.phpt \
		ldap2/connect.inc  ldap2/02fetch.phpt \
		ldap2/102errormap.phpt  ldap2/mktable.inc \
		ldap2/03simplequery.phpt ldap2/13limit.phpt \
		ldap2/setup.inc ldap2/05sequences.phpt \
		ldap2/14fetchmode_object.phpt ldap2/skipif.inc \
		ldap2/06prepexec.phpt ldap2/15quote.phpt \
		ldap2/slapd-2.0.conf  ldap2/08affectedrows.phpt \
		ldap2/20ldapsetparam.phpt  ldap2/slapd-2.1.conf \
		ldap2/09numrows.phpt  ldap2/21ldapgetoption.phpt \
		ldap3/01connect.phpt  ldap3/setup.inc \
		ldap3/slapd-2.1.conf  ldap3/21ldapgetoption.phpt \
		ldap3/skipif.inc  ldap3/connect.inc  ldap3/slapd-2.0.conf
_TESTSDIR=	tests
DOCS=		ldap2-connect.php  search-assoc.php \
		ldap3-connect.php  search-ordered.php
_DOCSDIR=	docs

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
