# New ports collection makefile for:	ja-lynx-current
# Version required:     2.8.2pre.5
# Date created:         10 August 1998
# Whom:                 Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	lynx2.8.2pre.5
PKGNAME=	ja-lynx-2.8.2.pre5
CATEGORIES=	japanese www
MASTER_SITES=	http://sol.slcc.edu/lynx/current/

MAINTAINER=	shige@FreeBSD.org

NO_LATEST_LINK=	YES
WRKSRC=		${WRKDIR}/lynx2-8-2
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-screen=ncurses --with-zlib --libdir="${PREFIX}/etc" \
		--disable-nls --enable-default-colors \
		--enable-nsl-fork --enable-persistent-cookies
MAKEFILE=	makefile
INSTALL_TARGET=	install install-help
MAN1=		lynx.1

post-install:
	@${INSTALL_DATA} ${WRKSRC}/lynx.cfg ${PREFIX}/etc/lynx.cfg.sample
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC} ; make install-doc)
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/lynx
	@${INSTALL_DATA} ${WRKSRC}/lynx.cfg ${PREFIX}/share/doc/lynx/samples/
.endif
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/lynx_help

.include <bsd.port.mk>
