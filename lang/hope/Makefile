# New ports collection makefile for:	hope
# Date created:				24 September 2001
# Whom:					Lev Serebryakov <lev@serebryakov.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	hope
PORTVERSION=	0.0
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://www.soi.city.ac.uk/~ross/Hope/
DISTNAME=	${PORTNAME}

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Hope is lazy interpriter for HOPE applicative language

.if defined(WITH_DOCS)
BUILD_DEPENDS+=	latex:${PORTSDIR}/print/teTeX \
		latex2html:${PORTSDIR}/textproc/latex2html
MAKE_ARGS+=	WITH_DOCS=yes
.else
NOPORTDOCS=	yes
.endif

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		hope.1

.include <bsd.port.pre.mk>

pre-fetch:
.if !defined(WITH_DOCS)
	@${ECHO} ""
	@${ECHO} "      If you want to build and install documentation"
	@${ECHO} "      you should use WITH_DOCS build option"
	@${ECHO} ""
	@${ECHO} "      Documentation is not builded by default because"
	@${ECHO} "      it needs latex and latex2html"
	@${ECHO} ""
.endif

.include <bsd.port.post.mk>
