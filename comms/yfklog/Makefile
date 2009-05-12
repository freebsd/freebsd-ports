# ports collection makefile for:	yflklog
# Date created:		17 October 2007
# Whom:			db
#
# $FreeBSD$
#

PORTNAME=	yfklog
PORTVERSION=	0.3.5
CATEGORIES=	comms hamradio
MASTER_SITES=	http://fkurz.net/ham/yfklog/ \
		${MASTER_SITE_LOCAL} \
		http://www.db.net/downloads/
MASTER_SITE_SUBDIR=	db
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz yfk.png
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}.tar.gz

MAINTAINER=	db@FreeBSD.org
COMMENT=	Amateur Radio curses based logging program

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Curses.pm:${PORTSDIR}/devel/p5-Curses \
		${SITE_PERL}/${PERL_ARCH}/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/${PERL_ARCH}/Hamlib.pm:${PORTSDIR}/comms/hamlib \
		${SITE_PERL}/Net/FTP/File.pm:${PORTSDIR}/net/p5-Net-FTP-File

USE_PERL5=	yes
NO_BUILD=	yes
MAN1=		yfklog.1

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/perl|${PERL}|' \
	     ${WRKSRC}/yfk ${WRKSRC}/yfksubs.pl
	@${REINPLACE_CMD} -e 's|prefix="/usr"|prefix="${PREFIX}"|' \
	     ${WRKSRC}/yfk ${WRKSRC}/yfksubs.pl
do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/yfk ${PREFIX}/bin/yfklog
	@${INSTALL_DATA} ${FILESDIR}/yfklog.1 ${MANPREFIX}/man/man1
	@${INSTALL_SCRIPT} ${WRKSRC}/yfksubs.pl ${PREFIX}/libexec/yfksubs.pl
	@${INSTALL_DATA} ${_DISTDIR}/yfk.png ${PREFIX}/share/pixmaps/yfklog.png
	@${MKDIR} ${DATADIR}
.for	f in cty.dat db_calls.sql db_clubs.sql \
	db_config.sql db_log.sql db_log.sqlite \
	zweckform3421.lab zweckform3475.lab zweckform3657.lab config
	@${INSTALL_DATA} ${WRKSRC}/$f ${DATADIR}
.endfor
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}/onlinelog
.for 	f in README  search.php test.txt
	@${INSTALL_DATA} ${WRKSRC}/onlinelog/$f ${EXAMPLESDIR}/onlinelog
.endfor
	@${MKDIR} ${EXAMPLESDIR}/clubs
.for	f in README hsc2sql.awk hscmember.txt
	@${INSTALL_DATA} ${WRKSRC}/clubs/$f ${EXAMPLESDIR}/clubs
.endfor
.endif
.if     !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for	f in AUTHORS CHANGELOG COPYING INSTALL MANUAL README RELEASENOTES
	@${INSTALL_DATA} ${WRKSRC}/$f ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
