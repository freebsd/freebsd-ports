# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gprbuild
PORTVERSION=	${SNAPSHOT}
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://downloads.dragonlace.net/src/
DISTNAME=	gprbuild-gpl-${YEAR}-src

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Adacore multi-language software build tool

LICENSE=	GPLv3

BUILD_DEPENDS=	xmlada>=4.4:textproc/xmlada

YEAR=		2015
SNAPSHOT=	20150506
USES=		ada
MAKE_ARGS=	PROCESSORS=${MAKE_JOBS_NUMBER}
PORTDOCS=	html txt pdf
CONHOST=	${CONFIGURE_TARGET}
INSTALL_TARGET=	install

OPTIONS_DEFINE=	DOCS
DOCS_INSTALL_TARGET=	install-docs

.include <bsd.port.options.mk>

post-patch:
	${CP} ${FILESDIR}/Makefile.BSD ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -i "" -e "s,@AUXPREFIX@,${PREFIX}/gcc5-aux," \
		${WRKSRC}/share/gprconfig/compilers.xml
	${SED} -e 's|@host@|${CONHOST}|' \
		${WRKSRC}/src/gprconfig-sdefault.ads.in > \
		${WRKSRC}/src/gprconfig-sdefault.ads
	${MV} ${WRKSRC}/share/gprconfig/*.orig ${WRKSRC}/obj-cov

.include <bsd.port.mk>
