# New ports collection makefile for:	distcc
# Date created:				25 June 2002
# Whom:					Frerich Raabe <frerich.raabe@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	distcc
PORTVERSION=	2.12.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://distcc.samba.org/ftp/distcc/

MAINTAINER=	clement@FreeBSD.org
COMMENT=	Distribute compilation of C(++) code acrosss machines on a network

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
WANT_GNOME=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	GNOME "Build GUI monitor based on GNOME" Off \
		GTK "Build GUI monitor based on GTK" Off

.include <bsd.port.pre.mk>

.if defined(WITH_GNOME)
USE_GNOME=	libgnomeui
CONFIGURE_ARGS+=	--with-gnome
PKGNAMESUFFIX=	-gnome
PLIST_SUB+=	WITH_GNOME=""
.elif defined(WITH_GTK)
USE_GNOME=	gtk20
CONFIGURE_ARGS+=	--with-gtk
PKGNAMESUFFIX=	-gtk
PLIST_SUB+=	WITH_GNOME=""
.else
PLIST_SUB+=	WITH_GNOME="@comment "
.endif

MAN1=		distcc.1 distccd.1
DOC_FILES=	AUTHORS INSTALL NEWS README \
		doc/protocol-1.txt doc/status-1.txt \
		doc/protocol-2.txt doc/reporting-bugs.txt

pre-install:
	@${SETENV} ${SCRIPTS_ENV} PKG_PREFIX="${PREFIX}" \
		${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/distcc ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/distccmon-text ${PREFIX}/bin
.if defined(WITH_GNOME) || defined(WITH_GTK)
	@${INSTALL_PROGRAM} ${WRKSRC}/distccmon-gnome ${PREFIX}/bin
.endif
	@${INSTALL_PROGRAM} ${WRKSRC}/distccd ${PREFIX}/sbin
	@${INSTALL_SCRIPT} -m 751 ${FILESDIR}/distccd.sh.sample \
		${PREFIX}/etc/rc.d/distccd.sh.sample

post-install: install-doc install-man
	@${TOUCH} /var/run/distccd.pid
	@${CHOWN} distcc:distcc /var/run/distccd.pid
	@${CAT} ${PKGMESSAGE}

install-doc:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

install-man:
.for file in ${MAN1}
	@${INSTALL_MAN} ${WRKSRC}/man/${file} ${MANPREFIX}/man/man1
.endfor

.include <bsd.port.post.mk>
