# New ports collection makefile for:	pavuk
# Version required:			0.9pl18
# Date created:				19 March 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=		pavuk-0.9pl18
PKGNAME=		pavuk-0.9.18
CATEGORIES=		ftp www
MASTER_SITES=		${MASTER_SITE_SUNSITE} \
			ftp://ftp.idata.sk/pub/unix/www/ \
			ftp://ftp.phacka.sk/pub/pavuk/ \
			http://www.idata.sk/~ondrej/sw/
MASTER_SITE_SUBDIR=	X11/gtkbuffet/apps/pavuk
EXTRACT_SUFX=		.tgz

MAINTAINER=		andy@icc.surw.chel.su

LIB_DEPENDS=		Xpm.4:${PORTSDIR}/graphics/xpm

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-xpm-includes=${X11BASE}/include --disable-gtk
USE_GMAKE=		yes

MAN1=			pavuk.1

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/src/pavuk ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/man/pavuk.1 ${PREFIX}/man/man1
	@ ${INSTALL_DATA} ${WRKSRC}/pavukrc.sample ${PREFIX}/etc
	@ ${INSTALL_DATA} ${WRKSRC}/pavuk_authinfo.sample ${PREFIX}/etc
	@ ${MKDIR} ${PREFIX}/share/locale/cs/LC_MESSAGES
	@ ${MKDIR} ${PREFIX}/share/locale/de/LC_MESSAGES
	@ ${MKDIR} ${PREFIX}/share/locale/sk/LC_MESSAGES
	@ ${INSTALL_DATA} ${WRKSRC}/po/cs.mo ${PREFIX}/share/locale/cs/LC_MESSAGES/pavuk.mo
	@ ${INSTALL_DATA} ${WRKSRC}/po/de.mo ${PREFIX}/share/locale/de/LC_MESSAGES/pavuk.mo
	@ ${INSTALL_DATA} ${WRKSRC}/po/sk.mo ${PREFIX}/share/locale/sk/LC_MESSAGES/pavuk.mo
	@ ${MKDIR} ${PREFIX}/share/icons
	@ ${INSTALL_DATA} ${WRKSRC}/icons/*.xpm ${PREFIX}/share/icons
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/pavuk
.for file in AUTHORS BUGS ChangeLog FAQ README THANK_TO TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/pavuk
.endfor
.endif

.include <bsd.port.mk>
