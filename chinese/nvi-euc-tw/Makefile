# New ports collection makefile for:	nvi-1.79 + multilingual patch(euc-tw)
# Version required:	1.79
# Date created:		5 Apr 1997
# Whom:			Jun-ichiro itojun Itoh &lt;itojun@itojun.org&gt;
#
# $Id: Makefile,v 1.3 1997/03/15 11:55:56 asami Exp $
#

# can't use PORTSDIR here, since we haven't included bsd.port.mk
FILESDIR=	${.CURDIR}/../../editors/nvi/files
PATCHDIR=	${.CURDIR}/../../editors/nvi/patches
PKGDIR=		${.CURDIR}/../../editors/nvi/pkg
COMMENT=	${.CURDIR}/pkg/COMMENT

.include &lt;${.CURDIR}/../../editors/nvi/Makefile&gt;

PKGNAME=	cn-nvi-euctw-1.79-970403-1000
CATEGORIES=	chinese editors

MAINTAINER=	itojun@itojun.org

CONFIGURE_ARGS=	--enable-multibyte=euc-tw --program-prefix=n
