# New ports collection makefile for:	abi-compliance-checker
# Date created:		August 21, 2009
# Whom:	      		bf <bf@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	abi-compliance-checker
PORTVERSION=	1.98.7
CATEGORIES=	devel perl5
MASTER_SITES=	http://github.com/lvc/abi-compliance-checker/archive/ \
		LOCAL/bf

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Checks binary compatibility of two versions of a C/C++ shared library

LICENSE=	LGPL20 GPLv2
LICENSE_COMB=	dual

.if defined(MAINTAINER_MODE) || defined(PACKAGE_BUILDING)
BUILD_DEPENDS?=	exctags:${PORTSDIR}/devel/ctags
RUN_DEPENDS?=	exctags:${PORTSDIR}/devel/ctags
USE_PERL5=	yes
.else
RUN_DEPENDS?=	exctags:${PORTSDIR}/devel/ctags
USE_PERL5_RUN=	yes
.endif
USE_GCC=	any

FETCH_ARGS?=	-Fpr
NO_BUILD=	yes
PLIST_FILES=	bin/${PORTNAME}.pl
WRKSRC=	${WRKDIR}/${PORTNAME}-${DISTNAME}

.include <bsd.port.pre.mk>

CPPFILT?=	/usr/bin/c++filt
CTAGS?=		exctags
GZ?=		/usr/bin/gzip
READELF?=	/usr/bin/readelf

.if ${ARCH} == "sparc64"
PICFLAG?=	-fPIC
.else
PICFLAG?=	-fpic
.endif

.for w in DATA DOCS
.ifndef(NOPORT${w})
PORT${w}=	*
.endif
.endfor

post-patch:
	@${REINPLACE_CMD} \
		-e "\|get_CmdPath(\"c++filt\")|s|\"c++filt\"|\"${CPPFILT}\"|" \
		-e "\|get_CmdPath(\"ectags\")|s|\"ectags\"|\"${CTAGS}\"|" \
		-e "\|get_CmdPath(\"gcc\")|s|\"gcc\"|\"${CC}\"|" \
		-e "\|get_CmdPath(\"objdump\")|s|\"objdump\"|\"${OBJDUMP}\"|" \
		-e "\|get_CmdPath(\"readelf\")|s|\"readelf\"|\"${READELF}\"|" \
		-e "\|my \$$GzipCmd =|s|=.*|= \"${GZ}\";|" \
		-e "\|my \$$TarCmd =|s|=.*|= \"${TAR}\";|" \
		-e "\|TarCmd -xv.*>|{h; s| >.*|\");|; x; s|-xv|-t|; G;}" \
		-e "s|ACC_MODULES_INSTALL_PATH|${DATADIR}|" \
		${WRKSRC}/${PORTNAME}.pl
	@${SED} -i "" -e "\|BuildCmd|s|GCC_PATH.\"|& ${PICFLAG}|" \
		${WRKSRC}/modules/Internals/RegTests.pm

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${PREFIX}/bin
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif
.ifndef(NOPORTDATA)
	@${MKDIR} ${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} \
	"modules/Internals modules/*.xml modules/Targets/unix" ${DATADIR})
.endif

.if defined(MAINTAINER_MODE) || defined(PACKAGE_BUILDING)
check regression-test test: build
	cd ${WRKSRC}; \
	${PERL} ./${PORTNAME}.pl -test; \
	${PERL} ./${PORTNAME}.pl -test-dump

.endif

.include <bsd.port.post.mk>
