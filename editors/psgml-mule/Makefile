# New ports collection makefile for:	psgml for mule
# Date created:		23 January 1999
# Whom:			shige
#
# $FreeBSD$
#

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A major mode for editing SGML and XML documents for mule

DEPRECATED=	emacs19 and related ports are obsolete; please use a more recent version
EXPIRATION_DATE=	2007-08-19

# This is a slave port.
MASTERDIR=	${.CURDIR}/../psgml

# emacs port setup
USE_EMACS=	yes
EMACS_PORT_NAME=	mule

BUILD_DEPENDS+=	makeinfo:${PORTSDIR}/print/texinfo

ALL_TARGET=	compile

post-build:
	cd ${WRKSRC} && makeinfo *.texi

.include "${MASTERDIR}/Makefile"
