# New ports collection makefile for:	distcc
# Date created:				25 June 2002
# Whom:					Frerich Raabe <frerich.raabe@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	distcc
PORTVERSION=	2.9
CATEGORIES=	devel
MASTER_SITES=	http://distcc.samba.org/ftp/distcc/

MAINTAINER=	dominic.marks@btinternet.com
COMMENT=	Distribute compilation of C(++) code acrosss machines on a network

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

PLIST_SUB+=	DOCSDIR=${DOCSDIR:S,${PREFIX}/,,}

WANT_GNOME=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mlibgnomeui} != ""
USE_GNOME=	libgnomeui
CONFIGURE_ARGS+=	"--enable-gnome"
PLIST_SUB+=	WITH_GNOME=""
.else
PLIST_SUB+=	WITH_GNOME="@comment "
.endif

MAN1=	distcc.1 distccd.1
DOC_FILES=	AUTHORS COPYING COPYING.FDL INSTALL NEWS README \
		doc/protocol-1.txt doc/status-1.txt

pre-fetch:
.if !defined(WITHOUT_GNOME)
	@${ECHO_MSG} "Building with GNOME-based monitor. To disable this, press"
	@${ECHO_MSG} "Ctrl+C now and restart with 'make WITHOUT_GNOME=yes'."
	@${ECHO_MSG} ""
.else
	@${ECHO_MSG} "Disabled GNOME-based monitor."
	@${ECHO_MSG} ""
.endif

pre-install:
	@${SETENV} ${SCRIPTS_ENV} PKG_PREFIX="${PREFIX}" \
		${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/distcc ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/distccmon-text ${PREFIX}/bin
.if !defined(WITHOUT_GNOME) && ${HAVE_GNOME:Mlibgnomeui} != ""
	@${INSTALL_PROGRAM} ${WRKSRC}/distccmon-gnome ${PREFIX}/bin
.endif
	@${INSTALL_PROGRAM} ${WRKSRC}/distccd ${PREFIX}/sbin
	${INSTALL_SCRIPT} -m 751 ${FILESDIR}/distccd.sh.sample \
		${PREFIX}/etc/rc.d/distccd.sh.sample

post-install: install-doc install-man
	@${TOUCH} /var/run/distccd.pid
	@${CHOWN} distcc:distcc /var/run/distccd.pid
	@${CAT} ${PKGMESSAGE}

install-doc:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

install-man:
.for file in ${MAN1}
	@${INSTALL_MAN} ${WRKSRC}/man/${file} ${MANPREFIX}/man/man1
.endfor

.include <bsd.port.post.mk>
