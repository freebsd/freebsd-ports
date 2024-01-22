PORTNAME=	mahjong
PORTVERSION=	1.16
PORTREVISION=	2
CATEGORIES=	games net
MASTER_SITES=	http://mahjong.julianbradfield.org/Source/%SUBDIR%/
DISTNAME=	mj-${PORTVERSION}-src

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Networked Mah Jong program, together with a computer player
WWW=		https://mahjong.julianbradfield.org/

LICENSE=	GPLv2+

USES=		compiler:c++11-lang gmake gnome perl5 pkgconfig
USE_GNOME=	gtk20
USE_PERL5=	build
MAKE_ENV=	CCLINK="${CC}" CDEBUGFLAGS="${CFLAGS}" PERL="${PERL}"

PLIST_FILES=	bin/mj-server bin/mj-player bin/xmj \
		share/man/man1/mj-player.1.gz share/man/man1/mj-server.1.gz \
		share/man/man1/xmj.1.gz

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CC|#CC|g ; \
		 s|^DESTDIR|#DESTDIR|g ; \
		 s|^CDEBUGFLAGS|#CDEBUGFLAGS|g ; \
		 s|^MAKE|#MAKE|g ; \
		 s|^PERL|#PERL|g ; \
		 s|^INST|#INST|g ; \
		 s|make |$$(MAKE) |g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|"gcc"|"${CC}"| ; \
		 s|^gcc |${CC} |' ${WRKSRC}/makedep
	@${REINPLACE_CMD} -e \
		's|SOL_TCP|IPPROTO_TCP|' ${WRKSRC}/sysdep.c

do-configure:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} \
		Makefile.in Makefile)

do-install:
.for i in mj-player mj-server xmj
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${i} \
		${STAGEDIR}${PREFIX}/bin/${i})
.endfor
	(cd ${WRKSRC} && ${INSTALL_MAN} xmj.man \
		${STAGEDIR}${PREFIX}/share/man/man1/xmj.1)
.for i in mj-player.1 mj-server.1
	${LN} -sf xmj.1 ${STAGEDIR}${PREFIX}/share/man/man1/${i}
.endfor

.include <bsd.port.mk>
