# Created by: Hye-Shik Chang <perky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dpkg
PORTVERSION=	1.17.20
CATEGORIES=	archivers sysutils
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	dpkg_${PORTVERSION}

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Debian package maintenance system

LICENSE=	GPLv2

BUILD_DEPENDS=	po4a:${PORTSDIR}/textproc/po4a
RUN_DEPENDS=	gtar:${PORTSDIR}/archivers/gtar \
		gpatch:${PORTSDIR}/devel/patch \
		gmd5sum:${PORTSDIR}/sysutils/coreutils

GNU_CONFIGURE=	yes
USES=		gmake iconv libtool perl5 pkgconfig tar:xz shebangfix
WRKSRC=		${WRKDIR}/dpkg-${PORTVERSION}
SHEBANG_FILES=	dselect/methods/ftp/update dselect/methods/ftp/install \
		dselect/methods/ftp/setup

DPKGDIR?=	/var/db/dpkg
PLIST_SUB+=	DPKGDIR=${DPKGDIR}

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST+=	DPKGDIR=${DPKGDIR}

CONFIGURE_ARGS+=--with-admindir=${DPKGDIR} --libdir=${PREFIX}/libexec \
		--program-transform-name="" --with-libintl-prefix=${LOCALBASE} \
		--disable-compiler-warnings
CONFIGURE_ENV+=	PERL_LIBDIR="${PREFIX}/${SITE_PERL_REL}"

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_OFF=	--disable-nls
NLS_USES=		gettext

post-patch:
	@${REINPLACE_CMD} 's|-t$$host|-t${ARCH}-freebsd|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -E 's/(md5|sha1|sha256)sum/g&/g' \
		${WRKSRC}/scripts/Dpkg/Checksums.pm
	@${REINPLACE_CMD} -e 's/cp -p $$(DEST/mv $$(DEST/g; s/rm $$(/rm -f $$(/g' \
		${WRKSRC}/scripts/mk/Makefile.in \
		${WRKSRC}/scripts/Makefile.in
	@${REINPLACE_CMD} 's/{^MATCH}/\&/' ${WRKSRC}/dselect/mkcurkeys.pl

post-install:
	(cd ${STAGEDIR}${DPKGDIR} && ${MKDIR} available diversions \
		statoverride status)

.include <bsd.port.mk>
