# ports collection makefile for:	yflklog
# Date created:		17 October 2007
# Whom:			db
#
# $FreeBSD$
#

PORTNAME=	yfklog
PORTVERSION=	0.3.4
CATEGORIES=	comms hamradio
MASTER_SITES=	http://fkurz.net/ham/yfklog/ \
		http://www.db.net/downloads/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db

MAINTAINER=	db@FreeBSD.org
COMMENT=	Amateur Radio curses based logging program

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Curses.pm:${PORTSDIR}/devel/p5-Curses \
		${SITE_PERL}/${PERL_ARCH}/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/Net/FTP.pm:${PORTSDIR}/net/p5-Net-FTP-File

USE_PERL5=	yes
NO_BUILD=	yes
MAN1=		yfklog.1

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/perl|${PERL}|' \
	     ${WRKSRC}/yfk ${WRKSRC}/yfksubs.pl
	@${REINPLACE_CMD} -e 's|prefix="/usr"|prefix="${PREFIX}"|' \
	     ${WRKSRC}/yfk ${WRKSRC}/yfksubs.pl
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/yfk ${PREFIX}/bin/yfklog
	${INSTALL_DATA} ${FILESDIR}/yfklog.1 ${MANPREFIX}/man/man1
	${MKDIR} ${DATADIR}
.for	f in ${WRKSRC}/cty.dat ${WRKSRC}/db_calls.sql db_clubs.sql \
	${WRKSRC}/db_config.sql ${WRKSRC}/db_log.sql ${WRKSRC}/db_log.sqlite \
	${WRKSRC}/zweckform3421.lab ${WRKSRC}/zweckform3475.lab yfksubs.pl \
	${WRKSRC}/zweckform3657.lab ${WRKSRC}/config
	@${INSTALL_DATA} ${WRKSRC}/$f ${DATADIR}
.endfor
	${MKDIR} ${EXAMPLESDIR}/onlinelog
.for 	f in ${WRKSRC}/onlinelog/README  ${WRKSRC}/onlinelog/search.php \
	${WRKSRC}/onlinelog/test.txt
	${INSTALL_DATA} ${WRKSRC}/$f ${EXAMPLESDIR}/onlinelog
.endfor
	${MKDIR} ${EXAMPLESDIR}/clubs
.for	f in ${WRKSRC}/clubs/README ${WRKSRC}/clubs/hsc2sql.awk \
	${WRKSRC}/clubs/hscmember.txt
	${INSTALL_DATA} ${WRKSRC}/$f ${EXAMPLESDIR}/clubs
.endfor
.if     !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for	d in ${WRKSRC}/AUTHORS ${WRKSRC}/CHANGELOG ${WRKSRC}/INSTALL \
	${WRKSRC}/MANUAL ${WRKSRC}/README ${WRKSRC}/RELEASENOTES
	@${INSTALL_DATA} ${WRKSRC}/${d} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
