# Created by: db
# $FreeBSD$

PORTNAME=	yfklog
PORTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=	comms hamradio
MASTER_SITES=	http://fkurz.net/ham/yfklog/ \
		LOCAL/db
DISTFILES=	${DISTNAME}.tar.gz yfk.png
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio curses based logging program

LICENSE=	GPLv2

RUN_DEPENDS=	p5-Curses>=0:devel/p5-Curses \
		p5-DBD-SQLite>=0:databases/p5-DBD-SQLite \
		p5-DBI>=0:databases/p5-DBI \
		hamlib>=0:comms/hamlib \
		p5-libwww>=0:www/p5-libwww \
		p5-Net-Telnet>=0:net/p5-Net-Telnet \
		p5-Net-FTP-File>=0:net/p5-Net-FTP-File

USES=		perl5

NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/perl|${PERL}|' \
	     ${WRKSRC}/yfk ${WRKSRC}/yfksubs.pl
	@${REINPLACE_CMD} -e 's|prefix="/usr"|prefix="${PREFIX}"|' \
	     ${WRKSRC}/yfk ${WRKSRC}/yfksubs.pl
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/yfk ${STAGEDIR}${PREFIX}/bin/yfklog
	${INSTALL_DATA} ${FILESDIR}/yfklog.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/yfklog
	${INSTALL_SCRIPT} ${WRKSRC}/yfksubs.pl ${STAGEDIR}${PREFIX}/share/yfklog/yfksubs.pl
	${INSTALL_DATA} ${_DISTDIR}/yfk.png ${STAGEDIR}${PREFIX}/share/pixmaps/yfklog.png
	${MKDIR} ${STAGEDIR}${DATADIR}
.for	f in cty.dat db_calls.sql db_clubs.sql \
	db_config.sql db_log.sql db_log.sqlite \
	zweckform3421.lab zweckform3475.lab zweckform3657.lab config
	${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${DATADIR}
.endfor
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/onlinelog
.for	f in README  search.php test.txt
	${INSTALL_DATA} ${WRKSRC}/onlinelog/$f ${STAGEDIR}${EXAMPLESDIR}/onlinelog
.endfor
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/clubs
.for	f in README
	${INSTALL_DATA} ${WRKSRC}/clubs/$f ${STAGEDIR}${EXAMPLESDIR}/clubs
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for	f in AUTHORS CHANGELOG COPYING INSTALL MANUAL README RELEASENOTES
	${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
