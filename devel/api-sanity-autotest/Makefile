# New ports collection makefile for:	api-sanity-autotest
# Date created:		February 16, 2009
# Whom:	      		bf <bf@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	api-sanity-checker
PORTVERSION=	1.12.9
CATEGORIES=	devel perl5
MASTER_SITES=	http://forge.ispras.ru/attachments/download/1278/ \
		LOCAL/bf

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Quickly generate sanity tests for the API of a C/C++ shared library

LICENSE=	LGPL20 GPLv2
LICENSE_COMB=	dual

NO_BUILD=	yes
.if defined(MAINTAINER_MODE) || defined(PACKAGE_BUILDING)
USE_PERL5=	yes
.else
USE_PERL5_RUN=	yes
.endif

PLIST_FILES=	bin/${PORTNAME}.pl

.include <bsd.port.pre.mk>

.if !empty(CC:M*clang*) || !empty(CXX:M*clang*)
IGNORE =	: this port requires CC and CXX to be versions of gcc
.endif

CPPFILT?=	/usr/bin/c++filt
READELF?=	/usr/bin/readelf

.if ${ARCH} == "sparc64"
PICFLAG?=	-fPIC
.else
PICFLAG?=	-fpic
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e "\|get_CmdPath(\"ar\")|s|\"ar\"|\"${AR}\"|" \
		-e "\|get_CmdPath(\"c++filt\")|s|\"c++filt\"|\"${CPPFILT}\"|" \
		-e "\|get_CmdPath(\"gcc\")|s|\"gcc\"|\"${CC}\"|" \
		-e "\|get_CmdPath(\"g++\")|s|\"g++\"|\"${CXX}\"|" \
		-e "\|get_CmdPath(\"objdump\")|s|\"objdump\"|\"${OBJDUMP}\"|" \
		-e "\|get_CmdPath(\"pidof\")|s|\"pidof\"|\"pgrep\"|" \
		-e "\|get_CmdPath(\"readelf\")|s|\"readelf\"|\"${READELF}\"|" \
		-e "s| -shared|& ${PICFLAG}|g" \
		${WRKSRC}/${PORTNAME}.pl

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${PREFIX}/bin

.if defined(MAINTAINER_MODE) || defined(PACKAGE_BUILDING)
check regression-test test: build
	cd ${WRKSRC}; ${PERL} ./${PORTNAME}.pl -test

.endif

.ifndef(NOPORTDOCS)
PORTDOCS=	Changes.html Descriptor.html Options.html Readme.html SpecType.html

post-install:
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc; ${INSTALL_MAN} ${PORTDOCS} ${DOCSDIR})

.endif
.include <bsd.port.post.mk>
