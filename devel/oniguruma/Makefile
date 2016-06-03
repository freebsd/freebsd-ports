# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	oniguruma
PORTVERSION=	2.5.8
CATEGORIES=	devel textproc
MASTER_SITES=	http://www.geocities.jp/kosako3/oniguruma/archive/:onig \
		http://www.SpringDaemons.com/stas/:ruby
DISTFILES=	onigd${PORTVERSION:S/./_/g}${EXTRACT_SUFX}:onig \
		ruby187p248-oniguruma.patch:ruby
DIST_SUBDIR=	ruby
EXTRACT_ONLY=	onigd${PORTVERSION:S/./_/g}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BSDL Regular Expressions library compatible with POSIX/GNU/Perl

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

WRKSRC=		${WRKDIR}/${PORTNAME}
CONFLICTS_INSTALL=	oniguruma-4.*
GNU_CONFIGURE=	yes
DOCS=		HISTORY README doc/*
OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/ruby187p248-oniguruma.patch \
		${WRKSRC}/ruby187.patch

post-configure:
	${SED} -e 's|%%PREFIX%%|${PREFIX}|' \
		${FILESDIR}/onig-config > ${WRKSRC}/onig-config

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/onig-config ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample/* ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
