# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	smake
PORTVERSION=	1.2.5
CATEGORIES=	devel
MASTER_SITES=	SF/s-make

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable make program with automake features

BROKEN_i386=	Does not compile

LICENSE=	CDDL GPLv2
LICENSE_COMB=	multi
LICENSE_FILE_CDDL=	${WRKSRC}/CDDL.Schily.txt

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/.a.*//g}

USES=		gmake tar:bzip2
MAKE_ENV=	CCOM="${CC}"
MAKE_ARGS=	INS_BASE=${PREFIX} DEFMANBASE=. CC="${CC}" CCOM="${CC}"

PLIST_SUB=	RULESUSED="${ARCH}-freebsd-cc"

MKLINKS=	${WRKSRC}/RULES/MKLINKS
GCCRULE=	${WRKSRC}/RULES/cc-gcc.rul

pre-build:
	@${REINPLACE_CMD} -e 's|gcc$$|${CC}|' ${GCCRULE}
	@${ECHO_CMD} "\$$symlink i386-freebsd-cc.rul ${ARCH}-freebsd-${CC}.rul" >> ${MKLINKS}

pre-install:
	${STRIP_CMD} ${WRKSRC}/smake/OBJ/${ARCH}-freebsd-${CC}/smake

.include <bsd.port.mk>
