# New ports collection makefile for:	kroc
# Date created:				15 January 2006
# Whom:					Tim Bishop <tdb@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kroc
PORTVERSION=	1.4.0
PORTREVISION=	4
CATEGORIES=	lang
MASTER_SITES=	http://www.cs.kent.ac.uk/projects/ofa/kroc/ \
		http://www.frmb.org/download/

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	The Kent Retargettable occam-pi Compiler

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

ONLY_FOR_ARCHS=	i386

USE_BZIP2=	yes
USE_SDL=	sdl

MAN1=		cputimerutil.1 mkoccdeps.1 occ21.1 kroc.1 kmakef.1
MAN3=		libconvert-inmos.3 libhostio-inmos.3 libmath-inmos.3 \
		libstreamio-inmos.3 libstring-inmos.3 libsock.3 \
		libfile.3 libproc.3 libcourse-cycles.3 libcourse-nets.3 \
		libcourse-utils.3 libsdlraster.3
MAN5=		kroc.conf.5

FAKEDIR=	${WRKDIR}/fake

RE_FILES=	build src/ccsp-1.6/common/rtsmain.c \
		src/kroc-1.4/kroc.in src/kroc-1.4/kroc.conf.5

post-patch:
.for i in ${RE_FILES}
	@${REINPLACE_CMD} \
		-e 's|%%PREFIX%%|${PREFIX}|' \
		-e 's|%%FAKEDIR%%|${FAKEDIR}|' \
		${WRKSRC}/$i
.endfor

# Path options to build are inconsistent
do-build:
	cd ${WRKSRC} && \
		SDL_CONFIG=${SDL_CONFIG} \
		./build \
		--prefix=${FAKEDIR} \
		--configdir=${FAKEDIR}/etc \
		--mandir=/man

FAKEDIR_FILES=	bin/kroc etc/kroc.conf

pre-install:
.ifdef(NOPORTDOCS)
	@cd ${FAKEDIR} && ${RM} -Rf share/kroc/doc
.endif
.for i in ${FAKEDIR_FILES}
	@${REINPLACE_CMD} \
		-e 's|${FAKEDIR}|${PREFIX}|' \
		${FAKEDIR}/$i
	@${RM} ${FAKEDIR}/$i.bak
.endfor

do-install:
	cd ${FAKEDIR} && ${TAR} -cf - . | ${TAR} -xf - -C ${PREFIX}

.include <bsd.port.mk>
