# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	oniguruma
PORTVERSION=	5.9.6
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel textproc
PKGNAMESUFFIX=	5
DISTNAME=	onig-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	rob@theseusnetworking.com
COMMENT=	BSDL Regular Expressions library compatible with POSIX/GNU/Perl

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	DOCS EXAMPLES

CONFLICTS=	oniguruma-2.*

USE_GITHUB=	yes
GH_ACCOUNT=	kkos

USES=		pathfix autoreconf libtool
PATHFIX_MAKEFILEIN=	Makefile.am
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		'/^INCLUDES/s|$$(includedir)|| ; \
		 s|$$(<)|$$(@).in|' ${WRKSRC}/Makefile.am

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} HISTORY README ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} * ${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/sample && ${INSTALL_DATA} *.c ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
