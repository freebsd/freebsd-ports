# New ports collection makefile for:	cli
# Date Created:				28 March 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cli
PORTVERSION=	20021101
CATEGORIES=	lang
MASTER_SITES=	http://download.microsoft.com/download/.netframesdk/cli3/1.0/wxp/en-us/
DISTNAME=	sscli_${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An implementation of the ECMA CLI and the ECMA C\# language

WRKSRC=		${WRKDIR}/sscli

RESTRICTED=	"license terms need to be reviewed"
IGNORE=		cannot be installed until you read and agree to the license terms
ONLY_FOR_ARCHS=	i386

USE_PERL5=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${BUILD_TYPE}
CONFIGURE_SCRIPT=	portconfigure
MAKEFILE=	makefile
MAKE_ENV=	CC_NAME="${CC}" SHELL="${SH}"
BUILD_TYPE=	free
PLIST_SUB=	CLI_VERSION="${PORTVERSION}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
GCC_LIB=	-lstdc++ -lgcc -lc_r -lc
.else
CFLAGS+=	-fpermissive
GCC_LIB=	-lstdc++ -lgcc -lc_r
.endif

post-extract:
	@${CP} ${SCRIPTDIR}/portconfigure ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e 's|%%GCC_LIB%%|${GCC_LIB}|g; \
		s|-fno-rtti ||g; \
		s|-fcheck-new ||g;' \
		${WRKSRC}/makefile.common.in \
		${WRKSRC}/rotorenv/bin/rotor_x86mk.inc
	@${FIND} ${WRKSRC}/rotorenv/bin -type f | ${XARGS} \
		${REINPLACE_CMD} -e 's|-Wno-non-virtual-dtor||g; \
		s|-Wno-non-template-friend||g;'
	@${FIND} ${WRKSRC}/clr/src -type f | ${XARGS} \
		${REINPLACE_CMD} -e 's|-Wno-ctor-dtor-privacy||g'

do-build:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ./buildall ${BUILD_TYPE})

.if !defined(I_AGREE_TO_LICENSE_TERMS)
pre-install:
	@${ECHO_MSG} "Please make sure that you have read and understood license terms contained in"
	@${ECHO_MSG} "the ${WRKSRC}/license.txt file and if you"
	@${ECHO_MSG} "agree with them then add -DI_AGREE_TO_LICENSE_TERMS to command line to"
	@${ECHO_MSG} "install the software (i.e. 'make -DI_AGREE_TO_LICENSE_TERMS install')."
	@${FALSE}
.endif

do-install:
	@${MKDIR} ${PREFIX}/cli-${PORTVERSION}
	@${INSTALL_DATA} ${WRKSRC}/license.txt ${PREFIX}/cli-${PORTVERSION}
	@cd ${WRKSRC}/build/v1.x86fre.rotor && ${FIND} . | \
		${CPIO} -pdmu -R ${LIBOWN}:${LIBGRP} \
		${PREFIX}/cli-${PORTVERSION}

.include <bsd.port.post.mk>
