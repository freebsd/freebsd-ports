# New ports collection makefile for:	subversion
# Date created:				10 September 2001
# Whom:					rooneg@electricjellyfish.net
#
# $FreeBSD$

PORTNAME=	subversion
PORTVERSION=	0.23.0
CATEGORIES=	devel
MASTER_SITES=	http://subversion.tigris.org/files/documents/15/4218/
MASTER_SITES+=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=		bmah

MAINTAINER=	rodrigc@attbi.com
COMMENT=	Version control system

LIB_DEPENDS=	db4:${PORTSDIR}/databases/db4 \
		neon.23:${PORTSDIR}/www/neon \
		expat.4:${PORTSDIR}/textproc/expat2 \
		apr-0.9:${PORTSDIR}/devel/apr
RUN_DEPENDS=	gdiff3:${PORTSDIR}/textproc/diffutils
BUILD_DEPENDS=	gdiff3:${PORTSDIR}/textproc/diffutils

INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes

WRKSRC=	${WRKDIR}/subversion-${PORTVERSION}
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-ssl \
		--with-neon=${LOCALBASE} \
		--with-berkeley-db=${LOCALBASE}/include/db4:${LOCALBASE}/lib \
		--with-apr=${LOCALBASE} \
		--with-apr-util=${LOCALBASE}

MAN1=	svn.1 svnadmin.1
MANCOMPRESSED=	no

post-extract:
	@${REINPLACE_CMD} 's/ldb/ldb4/g' ${WRKSRC}/configure

	@${RM} -r ${WRKSRC}/neon
	@${RM} -r ${WRKSRC}/apr
	@${RM} -r ${WRKSRC}/apr-util

post-configure:
	@${REINPLACE_CMD} 's/install-swig-py-lib//g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} 's/swig-py-lib//g' ${WRKSRC}/Makefile

post-install:
	install-info ${PREFIX}/info/svn-design.info ${PREFIX}/info/dir
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/doc/book; \
	${MAKE} INSTALL_DIR=${DOCSDIR} \
		install-book-html install-book-pdf install-book-ps
.endif

.include <bsd.port.mk>
