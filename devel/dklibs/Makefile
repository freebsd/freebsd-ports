# Ports collection makefile for:	dklibs
# Date created:				Jul 19, 2009
# Whom:					corky1951@comcast.net
#
# $FreeBSD$
#

PORTNAME=	dklibs
PORTVERSION=	1.23.1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	corky1951@comcast.net
COMMENT=	A set of libraries by Dirk Krause

LIB_DEPENDS=	png:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg \
		tiff:${PORTSDIR}/graphics/tiff \
		netpbm:${PORTSDIR}/graphics/netpbm

USE_BDB=	43+
USE_OPENSSL_BASE=	yes

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKEFILE=	Makefile-shared-linux
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include \
		-I${BDB_INCLUDE_DIR}

CONFIGURE_ARGS+=	--datadir=${DATADIR} \
			--sysconfdir=${ETCDIR}

CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"

# Need -lc for RELENG_6 support.
MAKE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib -L${BDB_LIB_DIR} -lc"

VERSION_PLUGIN=	1.23
MAJOR_VERSION=	1

PLIST_SUB+=	VERSION_PLUGIN="${VERSION_PLUGIN}" \
		MAJOR_VERSION="${MAJOR_VERSION}"

.if !defined(NO_INSTALL_MANPAGES)
MAN3=		dk.3 \
		dkapp.3 \
		dkbf.3 \
		dkbif.3 \
		dkconfig.3 \
		dkcp.3 \
		dkenc.3 \
		dkerror.3 \
		dkfont.3 \
		dkl2l.3 \
		dkle.3 \
		dklibs.3 \
		dkma.3 \
		dkmem.3 \
		dkof.3 \
		dkport.3 \
		dkproto.3 \
		dksdbi.3 \
		dksf.3 \
		dksfc.3 \
		dksignal.3 \
		dkslsupp.3 \
		dksto.3 \
		dkstr.3 \
		dkstream.3 \
		dkstt.3 \
		dktcpip.3 \
		dktok.3
MANCOMPRESSED=	no
.endif

post-install:
.if !defined(NO_INSTALL_MANPAGES)
	@${MKDIR} ${MAN3PREFIX}/man/man3
.for manpage in ${MAN3}
	${INSTALL_MAN} ${WRKSRC}/man/man3/${manpage} ${MAN3PREFIX}/man/man3
.endfor
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/DOCU/*.pdf ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/DOCU/*.png ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/DOCU/*.css ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/DOCU/*.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
