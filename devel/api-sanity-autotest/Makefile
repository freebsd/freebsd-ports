# New ports collection makefile for:	api-sanity-autotest
# Date created:		February 16, 2009
# Whom:	      		bf <bf@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	api-sanity-autotest
PORTVERSION=	1.12.5
CATEGORIES=	devel perl5
MASTER_SITES=	http://linuxtesting.org/downloads/ \
		LOCAL/bf

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Quickly generate sanity tests for the API of a C/C++ shared library

LICENSE=	LGPL20 GPLv2
LICENSE_COMB=	dual

NO_BUILD=	yes
.ifdef(MAINTAINER_MODE)
USE_PERL5=	yes
.else
USE_PERL5_RUN=	yes
.endif

PLIST_FILES=	bin/${PORTNAME}.pl

READELF?=	/usr/bin/readelf

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
PICFLAG?=	-fPIC
.else
PICFLAG?=	-fpic
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e "\|get_CmdPath(\"ar\")|s|\"ar\"|\"${AR}\"|" \
		-e "\|get_CmdPath(\"gcc\")|s|\"gcc\"|\"${CC}\"|" \
		-e "\|get_CmdPath(\"g++\")|s|\"g++\"|\"${CXX}\"|" \
		-e "\|get_CmdPath(\"objdump\")|s|\"objdump\"|\"${OBJDUMP}\"|" \
		-e "\|get_CmdPath(\"pidof\")|s|\"pidof\"|\"pgrep\"|" \
		-e "\|get_CmdPath(\"readelf\")|s|\"readelf\"|\"${READELF}\"|" \
		-e "s| -shared|& ${PICFLAG}|g" \
		${WRKSRC}/${PORTNAME}.pl

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${PREFIX}/bin

.ifdef(MAINTAINER_MODE)
check regression-test test: build
	@(cd ${WRKSRC}; ${PERL} ./${PORTNAME}.pl -test )

.endif

.ifndef(NOPORTDOCS)
PORTDOCS=	Changes.html Descriptor.html Options.html Readme.html SpecType.html

post-install:
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc; ${INSTALL_MAN} ${PORTDOCS} ${DOCSDIR})

.endif
.include <bsd.port.post.mk>
