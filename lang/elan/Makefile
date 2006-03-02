# New ports collection makefile for:	elan
# Date created:				19 Nov 2005
# Whom:					Ed Schouten <ed@fxq.nl>
#
# $FreeBSD$
#

PORTNAME=	elan
PORTVERSION=	1.7c
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.cs.ru.nl/pub/vb/
DISTNAME=	${PORTNAME}-1.7

MAINTAINER=	ed@fxq.nl
COMMENT=	Compiler for the Elan Programming Environment

LIB_DEPENDS=	dcg:${PORTSDIR}/devel/mimir

WRKSRC=	${WRKDIR}/${DISTNAME}

MAN1=	elancc.1

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

post-install:
.if !defined (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/manuals/compiler/comp.ps \
		${DOCSDIR}/elan-compiler.ps
	${INSTALL_DATA} ${WRKSRC}/manuals/language/elan.ps \
		${DOCSDIR}/elan-language.ps
.endif

.include <bsd.port.post.mk>
