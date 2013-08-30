# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rpm
PORTVERSION=	3.0.6
PORTREVISION=	15
CATEGORIES=	archivers
MASTER_SITES=	http://rpm5.org/files/rpm/rpm-3.0/ \
		http://rpm.org/releases/historical/rpm-3.0.x/ \
		http://www.mirrorservice.org/sites/ftp.rpm.org/pub/rpm/dist/rpm-3.0.x/

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	The Red Hat Package Manager

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

CONFLICTS=	rpm-[45].*

USES=		gmake
USE_AUTOTOOLS=	automake14 autoconf213 libtool
CONFIGURE_ARGS=	--with-glob
USE_LDCONFIG=	yes
MAKE_ENV=	OLD_PO_FILE_INPUT=1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib -lintl -liconv"
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

MAN1=		gendiff.1
MAN8=		rpm.8 rpm2cpio.8

X86_SUB=	"@comment "
AMD64_SUB=	"@comment "
PPC_SUB=	"@comment "
SPARC_SUB=	"@comment "
IA64_SUB=	"@comment "
.if ${ARCH} == i386
X86_SUB=	""
.elif ${ARCH} == amd64
AMD64_SUB=	""
.elif ${ARCH} == sparc64
SPARC_SUB=	""
.elif ${ARCH} == powerpc || ${ARCH} == powerpc64
PPC_SUB=	""
.elif ${ARCH} == ia64
IA64_SUB=	""
.endif

PLIST_SUB+=	X86=${X86_SUB} PPC=${PPC_SUB} SPARC=${SPARC_SUB} IA64=${IA64_SUB} AMD64=${AMD64_SUB}

post-patch:
.for file in rpm.c doc/rpm.8 lib/macro.c lib/rpmrc.c
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/${file}
.endfor

post-install:
		${INSTALL_MAN} ${WRKSRC}/doc/gendiff.1 ${PREFIX}/man/man1
		${INSTALL_MAN} ${WRKSRC}/doc/rpm.8 ${PREFIX}/man/man8
		${INSTALL_MAN} ${WRKSRC}/doc/rpm2cpio.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
