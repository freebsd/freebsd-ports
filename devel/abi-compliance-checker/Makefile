# New ports collection makefile for:	abi-compliance-checker
# Date created:		August 21, 2009
# Whom:	      		bf <bf@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	abi-compliance-checker
PORTVERSION=	1.94
CATEGORIES=	devel perl5
MASTER_SITES=	http://linuxtesting.org/downloads/ \
		LOCAL/bf

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Checks binary compatibility of two versions of a C/C++ shared library

LICENSE=	LGPL20 GPLv2
LICENSE_COMB=	dual

NO_BUILD=	yes
.ifdef(MAINTAINER_MODE)
USE_PERL5=	yes
.else
USE_PERL5_RUN=	yes
.endif

PLIST_FILES=	bin/${PORTNAME}.pl

CPPFILT?=	/usr/bin/c++filt
READELF?=	/usr/bin/readelf

.include <bsd.port.pre.mk>

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
		-e "\|get_CmdPath(\"ar\")|s|\"ar\"|\"${AR}\"|" \
		-e "\|get_CmdPath(\"c++filt\")|s|\"c++filt\"|\"${CPPFILT}\"|" \
		-e "\|get_CmdPath(\"gcc\")|s|\"gcc\"|\"${CC}\"|" \
		-e "\|get_CmdPath(\"objdump\")|s|\"objdump\"|\"${OBJDUMP}\"|" \
		-e "\|get_CmdPath(\"readelf\")|s|\"readelf\"|\"${READELF}\"|" \
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

.ifdef(MAINTAINER_MODE)
check regression-test test: build
	@(cd ${WRKSRC}; ${PERL} ./${PORTNAME}.pl -test )

.endif

.include <bsd.port.post.mk>
