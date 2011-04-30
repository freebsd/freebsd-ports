# New ports collection makefile for:	abi-compliance-checker
# Date created:		August 21, 2009
# Whom:	      		bf <bf@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	abi-compliance-checker
PORTVERSION=	1.21.12
CATEGORIES=	devel perl5
MASTER_SITES=	http://linuxtesting.org/downloads/ \
		LOCAL/bf

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Checks binary compatibility of two versions of a C/C++ shared library

LICENSE=	LGPL20 GPLv2
LICENSE_COMB=	dual

NO_BUILD=	yes
USE_PERL5_RUN=	yes

PLIST_FILES=	bin/${PORTNAME}.pl

CPPFILT?=	c++filt
READELF?=	readelf

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
PICFLAG?=	-fPIC
.else
PICFLAG?=	-fpic
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e "\|ArCmd =|s|=.*|= \"${AR}\";|" \
		-e "\|CPP_FILT =|s|=.*|= \"${CPPFILT}\";|" \
		-e "\|GCC_PATH =|s|=.*|= \"${CC}\";|" \
		-e "\|GPP_PATH =|s|=.*|= \"${CXX}\";|" \
		-e "\|ObjdumpCmd =|s|=.*|= \"${OBJDUMP}\";|" \
		-e "\|ReadelfCmd =|s|=.*|= \"${READELF}\";|" \
		-e "s|-shared|& ${PICFLAG}|g" \
		-e "s|detailes|details|g" \
		${WRKSRC}/${PORTNAME}.pl

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${PREFIX}/bin

check regression-test test: build
	@(cd ${WRKSRC} && ./${PORTNAME}.pl -test )

.ifndef(NOPORTDOCS)
PORTDOCS=	Changes.html Descriptor.html Options.html Readme.html

post-install:
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc; ${INSTALL_MAN} ${PORTDOCS} ${DOCSDIR})

.endif
.include <bsd.port.post.mk>
