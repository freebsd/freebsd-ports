# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gprbuild
PORTVERSION=	${SNAPSHOT}
CATEGORIES=	devel
MASTER_SITES=	http://downloads.dragonlace.net/src/
DISTNAME=	gprbuild-gpl-${YEAR}-src

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Adacore multi-language software build tool

LICENSE=	GPLv3

BUILD_DEPENDS+=	xmlada>=4.4:${PORTSDIR}/textproc/xmlada \
		gnat_util>=20140422:${PORTSDIR}/lang/gnat_util

YEAR=		2014
SNAPSHOT=	20140417
GNU_CONFIGURE=	yes
USES=		ada gmake
MAKE_ARGS+=	BUILD=production
MAKE_ARGS+=	PROCESSORS=${MAKE_JOBS_NUMBER}
PORTDOCS=	html txt pdf info
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

do-build:
#	Recreate the do-build target without -j parameter
#	It interferes with PROCESSORS make argument
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET})

post-patch:
	@${REINPLACE_CMD} -e "s,@AUXPREFIX@,${PREFIX}/gcc-aux," \
		${WRKSRC}/share/gprconfig/compilers.xml
	# Try_Help is part of GNAT Pro, but it's not in GCC 4.9 yet
	# It's not strictly needed. Before it just repeated usage.
	# There are other messages; just suppress Try_Help on 4 files
	${REINPLACE_CMD} -e '/Try_Help;/d' ${WRKSRC}/src/*-main.adb

post-install:
.if !${PORT_OPTIONS:MDOCS}
	${RM} -rf ${STAGEDIR}${DOCSDIR}
.endif
.if !${PORT_OPTIONS:MEXAMPLES}
	${RM} -rf ${STAGEDIR}${EXAMPLESDIR}
.endif
	cd ${STAGEDIR}${PREFIX}; ${FIND} share/examples -type d -empty | \
	  ${SORT} -dr | ${XARGS} ${RMDIR}

.include <bsd.port.mk>
