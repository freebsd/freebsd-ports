# New ports collection makefile for:	xshttpd
# Date created:				9 September 2010
# Whom:					Johan van Selst <johans@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	algol68g
PORTVERSION=	2.0.1
CATEGORIES=	lang
MASTER_SITES=	http://www.xs4all.nl/~jmvdveer/
DISTFILES=	${PORTNAME}-${PORTVERSION}.tgz
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}.tgz

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Alogol 68 Genie compiler

LIB_DEPENDS=	gsl.15:${PORTSDIR}/math/gsl

OPTIONS=	PLOT "GNU plot support" On \
		PGSQL "Postgresql support" On

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	-macosx
CONFIGURE_ENV+=	LOCALBASE=${LOCALBASE}
MAKEFILE=	makefile

MAN1=		a68g.1
PLIST_FILES=	bin/a68g include/a68g.h

.include <bsd.port.options.mk>

.ifdef WITH_PLOT
LIB_DEPENDS+=	plot.4:${PORTSDIR}/graphics/plotutils
.endif

.ifdef WITH_PGSQL
USE_PGSQL=	yes
.endif

post-install:
	@:
.ifndef NOPORTEXAMPLES
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/demo/* ${EXAMPLESDIR}
.endif
.ifndef NOPORTDOCS
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/${PORTDOCS} ${DOCSDIR}

PORTDOCS=	a68g-doc.pdf
DISTFILES+=	${PORTDOCS}
.endif

.ifndef NOPORTEXAMPLES
PORTEXAMPLES=	*
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not build on 6.X
.endif

.include <bsd.port.post.mk>
