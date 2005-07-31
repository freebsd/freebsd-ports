# New ports collection makefile for:	KMyMoney
# Date created:				21 June 2004
# Whom:					Alexander Novitsky
#
# $FreeBSD$
#

PORTNAME=	kmymoney2
PORTVERSION=	0.7.5
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	alecn2002@yandex.ru
COMMENT=	KDE-based personal finance assistant

USE_KDELIBS_VER=	3
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_PERL5=		yes
USE_BZIP2=		yes
USE_LIBTOOL_VER=	15
INSTALLS_SHLIB=		yes

MAN1=			kmymoney2.1
MANCOMPRESSED=		yes

DATADIR=		${PREFIX}/share/apps/${PORTNAME}
DOCSDIR=		${PREFIX}/share/doc/HTML/en/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not build on 4.x"
.endif

.include <bsd.port.post.mk>
