# New ports collection makefile for:	AEstats
# Date created:				27 Jan 2006
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aestats
PORTVERSION=	5.39
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_LOCAL} http://freebsd.nsu.ru/distfiles/
MASTER_SITE_SUBDIR=	danfe
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	An advanced HTML statistics generator for various games

ONLY_FOR_ARCHS=	i386

USE_ZIP=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/Linux-o
LINUXBINDIR=	${WRKSRC}/../Linux-Bin
MAKEFILE=	makefile
MAKE_ARGS=	cc=${CC}

post-extract: .SILENT
	${CP} ${FILESDIR}/fbsd_stub.c ${WRKSRC}
	${REINPLACE_CMD} -e 's,aes.o,& fbsd_stub.o,' ${WRKSRC}/${MAKEFILE}
	${ECHO_CMD} >> ${LINUXBINDIR}/alias-example.txt
	${MV} ${WRKSRC}/../unsupported/system/Unreal-225 ${WRKSRC}/../unrealmod

# This port is special.  Author does not distribute source code, but gives
# us Linux .o files instead.  With some hacking, we can build native FreeBSD
# executables from those .o files.  Pretty neat, huh?  :-)
#
pre-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -c fbsd_stub.c
	${OBJCOPY} --redefine-sym stdout=__stdoutp ${WRKSRC}/aespages.o
	${OBJCOPY} --redefine-sym stdout=__stdoutp ${WRKSRC}/paessubs.o

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/AEstats ${WRKSRC}/preAEs ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${LINUXBINDIR}/AEsscore.cfg \
		${LINUXBINDIR}/AEstats.cfg ${LINUXBINDIR}/banlist.txt ${DATADIR}
	${INSTALL_DATA} ${LINUXBINDIR}/alias-example.txt ${DATADIR}/alias.txt
	${INSTALL_DATA} ${WRKSRC}/../AEstats.txt ${DATADIR}
	cd ${WRKSRC}/.. && ${FIND} logs stats unrealmod | \
		${CPIO} -pdu -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}

.include <bsd.port.mk>
