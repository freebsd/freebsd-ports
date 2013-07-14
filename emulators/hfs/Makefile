# Created by: Jean-Marc Zucconi <jmz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hfs
DISTVERSION=	0_37
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	LOCAL/jmz
DISTNAME=	${PORTNAME}${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Read Macintosh HFS floppy disks, hard drives, and CD-ROMs

LICENSE=	GPLv2

CONFLICTS=	hfsutils-[0-9]*

DEPRECATED=	No upstream, no public distfiles; consider using 'sysutils/hfsutils'

USE_GMAKE=	yes
MAKE_ARGS=	CCPLUSPLUS="${CXX} -c" LD="${CXX}" DEBUG="${CFLAGS}" \
		INSTALLPATH="${PREFIX}" MANINSTALLDIR="${MANPREFIX}/man/man1"

MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README

OPTIONS_DEFINE=	ALIASES DOCS
ALIASES_DESC=	Install subcommand symbolic links

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MALIASES}
ALIASES=	bin/hcat bin/hcd bin/hdir bin/hls bin/hpwd bin/hread
PLIST_FILES+=	${ALIASES}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/.* ||' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|Volume::Enumerate|Enumerate|' \
		${WRKSRC}/volume.h

post-install:
.if ${PORT_OPTIONS:MALIASES}
.  for l in ${ALIASES}
	${LN} -sf ${PORTNAME} ${PREFIX}/${l}
.  endfor
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
