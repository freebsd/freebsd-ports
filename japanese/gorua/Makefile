# New ports collection makefile for:	goRua
# Date created:		12 December 2001
# Whom:			MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PORTNAME=	gorua
PORTVERSION=	0.12d
CATEGORIES=	japanese
MASTER_SITES=	http://www.unixuser.org/~haruyama/software/goRua/
DISTNAME=	goRua-${PORTVERSION}

MAINTAINER=	nobutaka@FreeBSD.org

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/gtk.so:${PORTSDIR}/x11-toolkits/ruby-gtk \
		${RUBY_SITEARCHLIBDIR}/zlib.so:${PORTSDIR}/archivers/ruby-zlib \
		${X11BASE}/lib/X11/fonts/local/mona6x12a.pcf.gz:${PORTSDIR}/japanese/monafonts

USE_BZIP2=	yes
USE_RUBY=	yes

NO_BUILD=	yes

CONFIG_FILES=	board_info bookmarks config gtkrc

do-configure:
	${SED} -e "s,%%RUBY_WITHOUT_SUFFIX%%,${RUBY_WITHOUT_SUFFIX}," < ${WRKSRC}/new_2ch_bbsmenu.rb > ${WRKSRC}/new_2ch_bbsmenu.rb.tmp
	${SED} -e "s,%%RUBY_WITHOUT_SUFFIX%%,${RUBY_WITHOUT_SUFFIX}," < ${WRKSRC}/goRua.rb > ${WRKSRC}/goRua.rb.tmp
	${MV} ${WRKSRC}/new_2ch_bbsmenu.rb.tmp ${WRKSRC}/new_2ch_bbsmenu.rb
	${MV} ${WRKSRC}/goRua.rb.tmp ${WRKSRC}/goRua.rb

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/goRua.rb ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/new_2ch_bbsmenu.rb ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/connect2ch.rb ${RUBY_SITELIBDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ja/goRua
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ja/goRua
.endif
	${MKDIR} ${PREFIX}/share/examples/goRua/dot.goRua_2ch
	${MKDIR} ${PREFIX}/share/examples/goRua/dot.goRua_2ch
	${MKDIR} ${PREFIX}/share/examples/goRua/dot.goRua_2ch/subject
	${MKDIR} ${PREFIX}/share/examples/goRua/dot.goRua_2ch/thread
.for f in ${CONFIG_FILES}
	${INSTALL_DATA} ${WRKSRC}/.goRua_2ch/${f} ${PREFIX}/share/examples/goRua/dot.goRua_2ch
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
