# New ports collection makefile for:	bforce-kst
# Date created:		1 May 2002
# Whom:			Andrew Dolgov <fox@furry.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	bforce
PORTVERSION=	0.22.8.7
CATEGORIES=	comms
MASTER_SITES=	http://kst.spb.ru/bforce/
PKGNAMESUFFIX=	-kst
DISTNAME=	${PORTNAME}-0.22.8.kst7

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple ifcico like Fidonet technology mailer

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

CONFIGDIR=	/etc/fido/bforce

FIXME=		include/bforce.h include/util.h include/logger.h \
		bforce/bforce.c bforce/conf_proc.c bforce/conf_read.c bforce/daemon.c \
		bforce/daemon_branch.c bforce/daemon_call.c  bforce/daemon_lines.c \
		bforce/expression.y bforce/freq_proc.c bforce/freq_wazoo.c bforce/io_modem.c \
		bforce/io_tcpip.c bforce/io_unix_lock.c bforce/io_unix_modem.c \
		bforce/io_unix_tio.c bforce/io_unix_tty.c bforce/logger.c bforce/nodelist.c \
		bforce/os_unix.c bforce/outb_sysqueue.c bforce/prot_common.c bforce/prot_binkp.c \
		bforce/prot_binkp_misc.c bforce/prot_hydra.c bforce/prot_zmmisc.c \
		bforce/prot_zmrecv.c bforce/prot_zmsend.c bforce/prot_yoohoo.c \
		bforce/prot_yoohoo_api.c bforce/prot_emsi.c bforce/prot_emsi_misc.c \
		bforce/prot_emsi_api.c bforce/sess_call.c bforce/sess_answ.c bforce/sess_init.c \
		bforce/sess_main.c bforce/u_misc.c bforce/u_time.c bforce/u_recode.c \
		bforce/u_plock.c bfutil/bfindex.c

WRKSRC=		${WRKDIR}/${DISTNAME}/source

pre-configure:
	${MKDIR} ${WRKSRC}/bin

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/bforce,${CONFIGDIR},g' ${WRKSRC}/Makefile.in
.for i in ${FIXME}
	@${REINPLACE_CMD} -e 's,log(,bf_log(,g' ${WRKSRC}/${i}
.endfor

do-install:
	${MKDIR} ${PREFIX}/etc/bforce
	${INSTALL_DATA} ${WRKSRC}/../examples/bforce.conf ${PREFIX}/etc/bforce/bforce.conf.sample
	${INSTALL_DATA} ${WRKSRC}/../examples/bforce.passwd ${PREFIX}/etc/bforce/bforce.passwd.sample
	${INSTALL_DATA} ${WRKSRC}/../examples/bforce.subst ${PREFIX}/etc/bforce/bforce.subst.sample
	${INSTALL_DATA} ${WRKSRC}/../examples/freq.aliases ${PREFIX}/etc/bforce/freq.aliases.sample
	${INSTALL_DATA} ${WRKSRC}/../examples/freq.dirs ${PREFIX}/etc/bforce/freq.dirs.sample
	${INSTALL_PROGRAM} ${WRKSRC}/bin/bforce ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/bfindex ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/bfstat ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/nlookup ${PREFIX}/bin

.include <bsd.port.mk>
