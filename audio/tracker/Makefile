# New ports collection makefile for:	tracker
# Date created:		2 Oct 1994
# Whom:			swallace
#
# $FreeBSD$
#

PORTNAME=	tracker
PORTVERSION=	5.3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_NETBSD}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MOD player

RESTRICTED=	"Non-redistributable beta"

WRKSRC=		${WRKDIR}/tracker
INSTALL_TARGET=	install install.info
MAKE_ARGS=	CC="${CC}" PREFIX="${PREFIX}" \
		MACHINE=freebsd COMPRESSION_FILE="${PREFIX}/etc/compression_methods" \
		CFLAGS="${CFLAGS} -funroll-loops -finline-functions"

INFO=		tracker
PLIST_FILES=	bin/randomize bin/tracker etc/compression_methods
PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e 's,machine/soundcard.h,sys/soundcard.h,' \
		${WRKSRC}/Arch/PCux/audio.c

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/tracker/html
.for docfile in FAQ readme tracker.doc
	${INSTALL_DATA} ${WRKSRC}/Docs/${docfile} ${PREFIX}/share/doc/tracker
.endfor
	${INSTALL_DATA} ${WRKSRC}/Docs/Html/* ${PREFIX}/share/doc/tracker/html
.endif

.include <bsd.port.mk>
