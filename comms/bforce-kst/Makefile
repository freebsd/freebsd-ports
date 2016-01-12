# Created by: Andrew Dolgov <fox@furry.spb.ru>
# $FreeBSD$

PORTNAME=	bforce
PORTVERSION=	0.22.8.7
PORTREVISION=	3
CATEGORIES=	comms
MASTER_SITES=	SF/binkleyforce/${PORTNAME}/0.22.8.kst7
PKGNAMESUFFIX=	-kst
DISTNAME=	${PORTNAME}-0.22.8.kst7

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple ifcico like Fidonet technology mailer

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/../COPYING

USES=		gmake
GNU_CONFIGURE=	yes

CONTRIBS=	bfha/README bfha/bfha.pl bflan callout.sh outman timesync.tcl \
		u-srif/conf/report.footer u-srif/conf/report.header u-srif/conf/u-srif.aliases \
		u-srif/conf/u-srif.conf u-srif/conf/u-srif.dirs u-srif/lib/uconfig.py \
		u-srif/lib/udbase.py u-srif/lib/ufido.py u-srif/lib/unodestat.py \
		u-srif/lib/utmpl.py u-srif/lib/uutil.py u-srif/u-srif-index.py \
		u-srif/u-srif-lookup.py u-srif/u-srif.py

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

SUB_FILES=	pkg-message

DOCS=		CHANGES CHANGES.kst COPYING README README.kst

OPTIONS_DEFINE=	DOCS

pre-configure:
	@${MKDIR} ${WRKSRC}/bin

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/bforce,/etc/fido/bforce,g' ${WRKSRC}/Makefile.in
.for i in ${FIXME}
	@${REINPLACE_CMD} -e 's,log(,bf_log(,g' ${WRKSRC}/${i}
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/fido/bforce
	${INSTALL_DATA} ${WRKSRC}/../examples/bforce.conf ${STAGEDIR}${PREFIX}/etc/fido/bforce/bforce.conf.sample
	${INSTALL_DATA} ${WRKSRC}/../examples/bforce.passwd ${STAGEDIR}${PREFIX}/etc/fido/bforce/bforce.passwd.sample
	${INSTALL_DATA} ${WRKSRC}/../examples/bforce.subst ${STAGEDIR}${PREFIX}/etc/fido/bforce/bforce.subst.sample
	${INSTALL_DATA} ${WRKSRC}/../examples/freq.aliases ${STAGEDIR}${PREFIX}/etc/fido/bforce/freq.aliases.sample
	${INSTALL_DATA} ${WRKSRC}/../examples/freq.dirs ${STAGEDIR}${PREFIX}/etc/fido/bforce/freq.dirs.sample

	${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${DATADIR}/bfha ${STAGEDIR}${DATADIR}/u-srif/conf ${STAGEDIR}${DATADIR}/u-srif/lib
.for i in ${CONTRIBS}
	${INSTALL_DATA} ${WRKSRC}/../contrib/${i} ${STAGEDIR}${DATADIR}/${i}
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/bin/bforce ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/bfindex ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/bfstat ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/nlookup ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/../,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
