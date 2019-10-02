# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	thoteditor
PORTVERSION=	2.1e
PORTREVISION=	4
CATEGORIES=	editors www
MASTER_SITES=	ftp://ftp.inrialpes.fr/pub/opera/sources/thot/ \
		ftp://ftp.ruhr-uni-bochum.de/local/jk.collection/thot/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Structured document editor, offering a graphical WYSIWYG interface

THOT_SUBDIR=	Target
USES=		gmake motif xorg
USE_XORG=	ice sm x11 xext xt
WRKSRC=		${WRKDIR}/Thot/${THOT_SUBDIR}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-thot --enable-plugin --without-insure --without-amaya \
		--disable-java --disable-intr --disable-jit --disable-math \
		--disable-ilu
ALL_TARGET=	all schemas
SUB_FILES=	thoteditor
MAKE_JOBS_UNSAFE=	yes

post-extract:
	@${MKDIR} ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} 's|-g -O|${CFLAGS}|' \
		${WRKDIR}/Thot/configure
	@${REINPLACE_CMD} 's|%%MOTIFLIB%%|${MOTIFLIB}|' \
		${WRKDIR}/Thot/thot/Makefile.in
	@${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|' \
		${WRKDIR}/Thot/thotlib/base/registry.c
	@${REINPLACE_CMD} 's|/usr/wsrc/|/usr/tmp/|' \
		${WRKDIR}/Thot/thotlib/include/sysdep.h

do-configure:
	(cd ${WRKSRC};../configure ${CONFIGURE_ARGS})

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/thot/doc
	${INSTALL_SCRIPT} ${WRKDIR}/thoteditor ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/Thot/tools/cextract-1.7/cextract.man \
		${STAGEDIR}${PREFIX}/man/man1/cextract.1
	${INSTALL_MAN} ${WRKDIR}/Thot/tools/cextract-1.7/cextrc.5 \
		${STAGEDIR}${PREFIX}/man/man5

.include <bsd.port.mk>
