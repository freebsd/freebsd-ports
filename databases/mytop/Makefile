# New ports collection makefile for:	mytop
# Date created:				28 Augest 2000
# Whom:	      				Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	mytop
PORTVERSION=	0.5
CATEGORIES=	databases
MASTER_SITES=	http://public.yahoo.com/~jzawodn/mytop/
EXTRACT_SUFX=	.gz

MAINTAINER=	leeym@cae.ce.ntu.edu.tw

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Term/ANSIColor.pm:${PORTSDIR}/devel/p5-Term-ANSIColor \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-Mysql

USE_PERL5=	yes

NO_WRKSUBDIR=	yes

MAN1=		mytop.1
POD2MAN?=	/usr/bin/pod2man

do-extract:
	@${MKDIR} ${WRKDIR}
	@${GUNZIP_CMD} -c ${DISTDIR}/${DISTFILES} > ${WRKDIR}/${PORTNAME}

do-build:
	@${POD2MAN} ${WRKDIR}/${PORTNAME} > ${WRKDIR}/${PORTNAME}.1

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/${PORTNAME}.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
