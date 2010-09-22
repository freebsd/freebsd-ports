# New ports collection makefile for:	NAnt
# Date created:		2005-5-21
# Whom:		Christopher Nehren <apeiron+ports@coitusmentis.info>
#
# $FreeBSD$
#   $Id: Makefile,v 1.14 2007/02/07 15:50:37 killfill Exp $
#

PORTNAME=	nant
PORTVERSION=	0.90
CATEGORIES=	devel
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A .NET build tool inspired by Ant

BUILD_DEPENDS=	mono:${PORTSDIR}/lang/mono
RUN_DEPENDS=	mono:${PORTSDIR}/lang/mono

DATADIR=	${PREFIX}/share/NAnt
INSTALL_TARGET=	install prefix=${PREFIX}
MAKE_ENV=	MONO_PATH=${WRKSRC}/lib
MAKE_JOBS_UNSAFE=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e '/install.pkgconfigdir/ s|lib/pkgconfig|libdata/pkgconfig|' ${WRKSRC}/NAnt.build
	@${FIND} ${WRKSRC}/src  ${WRKSRC}/tests -name '*.build' | ${XARGS} ${REINPLACE_CMD} -e \
		's|warnaserror="true"|warnaserror="false"|g;'

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc; ${FIND} . | ${CPIO} -pdmv -R ${DOCOWN}:${DOCGRP} ${DOCSDIR})
	@${CHMOD} -R ugo-w,ugo+rX ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples; ${FIND} . | ${CPIO} -pdmv -R ${DOCOWN}:${DOCGRP} ${EXAMPLESDIR})
	@${CHMOD} -R ugo-w,ugo+rX ${EXAMPLESDIR}
.endif

.include "${PORTSDIR}/lang/mono/bsd.mono.mk"
.include <bsd.port.post.mk>
