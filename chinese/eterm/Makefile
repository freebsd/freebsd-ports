# New ports collection makefile for:	eterm
# Date created:        24th December 2000
# Whom:                Michael C. Wu
# $FreeBSD$

PORTNAME=	eterm
PORTVERSION=	0.9
CATEGORIES=	chinese x11
MASTER_SITES=	ftp://ftp.enlightenment.org/pub/enlightenment/Eterm/ \
		ftp://ftp.dti.ad.jp/pub/X/enlightenment/Eterm/ \
		ftp://ftp.kddlabs.co.jp/.10/X11/window_manager/enlightenment/Eterm/ \
		ftp://ftp.sogang.ac.kr/.c/tools/X11/Enlightenment/Eterm/
DISTNAME=	Eterm-${PORTVERSION}

MAINTAINER=	ports@freebsd.org

BUILD_DEPENDS=	man2html:${PORTSDIR}/textproc/man2html
RUN_DEPENDS=	${X11BASE}/lib/X11/fonts/local/kc15f.pcf.gz:${PORTSDIR}/chinese/kcfonts

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	imlib
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--enable-trans=imlib --enable-multi-charset=big5 \
		--enable-xim --with-theme-update

CONFIGURE_ENV=	LIBS="-lxpg4"

MAN1=		Eterm.1
INSTALLS_SHLIB=	yes

pre-patch:
	@${PERL} -pi -e 's,<malloc.h>,<stdlib.h>,' \
		${WRKSRC}/libmej/debug.c ${WRKSRC}/libmej/strings.c

post-install:
	@${CHMOD} 4711 ${PREFIX}/bin/Eterm
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/Eterm
	@${INSTALL_DATA} ${WRKSRC}/ReleaseNotes ${PREFIX}/share/doc/Eterm
	@${INSTALL_DATA} ${WRKSRC}/doc/Eterm.1.html ${PREFIX}/share/doc/Eterm
	@${INSTALL_DATA} ${WRKSRC}/doc/Eterm_reference.html ${PREFIX}/share/doc/Eterm
	@${INSTALL_DATA} ${WRKSRC}/doc/Eterm.tcap ${PREFIX}/share/doc/Eterm
	@${INSTALL_DATA} ${WRKSRC}/doc/Eterm.ti ${PREFIX}/share/doc/Eterm
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
