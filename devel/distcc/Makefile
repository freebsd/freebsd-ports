# New ports collection makefile for:	distcc
# Date created:				25 June 2002
# Whom:					Frerich Raabe <frerich.raabe@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	distcc
PORTVERSION=	2.7
CATEGORIES=	devel
MASTER_SITES=	http://distcc.samba.org/ftp/distcc/

MAINTAINER=	frerich.raabe@gmx.de
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
DOC_FILES=	AUTHORS COPYING COPYING.FDL DEPENDENCIES INSTALL NEWS README \
		linuxdoc/distcc.sgml doc/protocol-1.txt doc/status-1.txt
HTML_DOC_FILES=	distcc.html distcc-1.html distcc-2.html distcc-3.html \
		distcc-4.html distcc-5.html

pre-fetch:
.if !defined(WITHOUT_GNOME)
	@${ECHO_MSG} "Building with GNOME-based monitor. To disable this, press"
	@${ECHO_MSG} "Ctrl+C now and restart with 'make WITHOUT_GNOME=yes'."
	@${ECHO_MSG} ""
.else
	@${ECHO_MSG} "Disabled GNOME-based monitor."
	@${ECHO_MSG} ""
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/distcc ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/distccmon-text ${PREFIX}/bin
.if !defined(WITHOUT_GNOME)
	@${INSTALL_PROGRAM} ${WRKSRC}/distccmon-gnome ${PREFIX}/bin
.endif
	@${INSTALL_PROGRAM} ${WRKSRC}/distccd ${PREFIX}/sbin

post-install: install-doc install-html-doc install-man
	@${CAT} ${PKGMESSAGE}

install-doc:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

install-html-doc:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/html
.for file in ${HTML_DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/linuxdoc/html/${file} ${DOCSDIR}/html
.endfor
.endif

install-man:
.for file in ${MAN1}
	@${INSTALL_MAN} ${WRKSRC}/man/${file} ${MANPREFIX}/man/man1
.endfor

.include <bsd.port.post.mk>
