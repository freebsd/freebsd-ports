# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	oniguruma
PORTVERSION=	5.9.5
PORTREVISION=	1
CATEGORIES=	devel textproc
MASTER_SITES=	http://www.geocities.jp/kosako3/oniguruma/archive/
PKGNAMESUFFIX=	5
DISTNAME=	onig-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BSDL Regular Expressions library compatible with POSIX/GNU/Perl

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	DOCS EXAMPLES

CONFLICTS=	oniguruma-2.*

USES=		libtool pathfix
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		'/^INCLUDES/s|$$(includedir)|| ; \
		 s|$$(<)|$$(@).in|' ${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} HISTORY README ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} * ${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/sample && ${INSTALL_DATA} *.c ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
