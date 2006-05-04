# New ports collection makefile for:	NAnt
# Date created:		2005-5-21
# Whom:		Christopher Nehren <apeiron+ports@coitusmentis.info>
#
# $FreeBSD$
#   $Id: Makefile,v 1.10 2006/01/11 03:54:20 tmclau02 Exp $
#

PORTNAME=	nant
DISTVERSION=	0.85r3
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-0.85-rc3-src

MAINTAINER=	apeiron+ports@coitusmentis.info
COMMENT=	A .NET build tool inspired by Ant

BUILD_DEPENDS=	mono:${PORTSDIR}/lang/mono
RUN_DEPENDS=	mono:${PORTSDIR}/lang/mono

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}

USE_GMAKE=	yes
MAKE_ENV=	MONO_PATH=${WRKSRC}/lib
INSTALL_TARGET=	install prefix=${PREFIX}

post-patch:
	@${FIND} ${WRKSRC}/src  ${WRKSRC}/tests -name '*.build' | ${XARGS} ${REINPLACE_CMD} -e \
		's|warnaserror="true"|warnaserror="false"|g;'

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/doc; ${FIND} . \
	| ${CPIO} -pdmv -R ${DOCOWN}:${DOCGRP} ${DOCSDIR}
	@${CHMOD} -R ugo-w,ugo+rX ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/examples; ${FIND} . \
	| ${CPIO} -pdmv -R ${DOCOWN}:${DOCGRP} ${EXAMPLESDIR}
	@${CHMOD} -R ugo-w,ugo+rX ${EXAMPLESDIR}
.endif

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
