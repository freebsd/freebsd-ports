# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	oniguruma
PORTVERSION=	5.9.4
CATEGORIES=	devel textproc
MASTER_SITES=	http://www.geocities.jp/kosako3/oniguruma/archive/
DISTNAME=	onig-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BSDL Regular Expressions library compatible with POSIX/GNU/Perl

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	DOCS EXAMPLES

CONFLICTS=	oniguruma-2.*

PKGNAMESUFFIX=	5

USES=		pathfix
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		'/^INCLUDES/s|$$(includedir)|| ; \
		 s|$$(<)|$$(@).in|' ${WRKSRC}/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} HISTORY README ${DOCSDIR})
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} * ${DOCSDIR})
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/sample && ${INSTALL_DATA} *.c ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
