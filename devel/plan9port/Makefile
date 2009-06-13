# New ports collection makefile for:	plan9port
# Date created:				Wed Mar 31 17:11:24 EST 2004
# Whom:					Serge Gagnon serge.gagnon@b2b2c.ca
#
# $FreeBSD$
#

PORTNAME=	plan9port
PORTVERSION=	20080909
PORTREVISION=	1
CATEGORIES=	devel plan9
MASTER_SITES=	http://swtch.com/plan9port/ \
		ftp://quenix2.dyndns.org/FreeBSD/ports/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	serge.gagnon.1@ulaval.ca
COMMENT=	Port of the bulk of the Plan9 software build environment to Unix

USE_XORG=	x11 xt xi xaw
USE_PERL5_BUILD=YES
WRKSRC=		${WRKDIR}/plan9
PLIST=		${WRKDIR}/.PLIST
SUB_FILES=	pkg-message
REINPLACE_ARGS=	-i ""
ONLY_FOR_ARCHS=	i386

PLAN9=		${PREFIX}/plan9
MANPREFIX=	${PLAN9}

MAN1=		9term.1 acmeevent.1 ascii.1 acme.1 9p.1 basename.1 cal.1 \
		calendar.1 cat.1 cleanname.1 cmp.1 comm.1 date.1 db.1 \
		dc.1 deroff.1 dict.1 diff.1 echo.1 ed.1 factor.1 fmt.1 \
		fortune.1 freq.1 grep.1 hoc.1 man.1 idiff.1 join.1 ls.1 \
		mc.1 mkdir.1 plumb.1 rc.1 rio.1 rm.1 sam.1 seq.1 sleep.1 \
		sort.1 spell.1 split.1 strings.1 sum.1 tail.1 tcs.1 \
		tee.1 test.1 time.1 touch.1 tr.1 uniq.1 wc.1 xd.1 yacc.1 \
		acid.1 stats.1 graph.1 9.1 gview.1 plot.1 scat.1 eqn.1 \
		grap.1 pic.1 tbl.1 troff.1 0intro.1 9c.1 astro.1 bc.1 \
		bundle.1 clog.1 colors.1 core.1 crop.1 cvs.1 dial.1 \
		doctype.1 fsize.1 gzip.1 install.1 jpg.1 kill.1 label.1 \
		lex.1 look.1 map.1 mk.1 mk9660.1 namespace.1 news.1 p.1 \
		page.1 pr.1 proof.1 ps.1 psfonts.1 pwd.1 secstore.1 \
		sed.1 src.1 tr2post.1 troff2html.1 tweak.1 units.1 vac.1 \
		web.1 wintext.1 ndb.1 passwd.1 secstored.1 tar.1 pem.1 \
		readcons.1 rsa.1 ssh-agent.1 netfiles.1 sftpcache.1 \
		hist.1 venti.1 yesterday.1 hget.1 snarfer.1 htmlroff.1 \
		resample.1 devdraw.1 mount.1 hg.1

MAN3=		ioproc.3 bio.3 fmtinstall.3 isalpharune.3 print.3 rune.3 \
		runestrcat.3 thread.3 9p.3 matrix.3 arith3.3 ctime.3 \
		memory.3 needstack.3 opentemp.3 addpt.3 aes.3 allocimage.3 \
		arg.3 proto.3 atof.3 pushtls.3 rfork.3 bin.3 blowfish.3 \
		cachechars.3 cleanname.3 color.3 complete.3 cputime.3 \
		des.3 dial.3 dirread.3 draw.3 dsa.3 dup.3 elgamal.3 \
		encode.3 errstr.3 event.3 exec.3 exits.3 fcall.3 flate.3 \
		frame.3 genrandom.3 getcallerpc.3 getenv.3 getsnarf.3 \
		get9root.3 mux.3 getns.3 getfields.3 post9pservice.3 \
		getuser.3 getwd.3 graphics.3 html.3 mach-cmd.3 ip.3 \
		keyboard.3 lock.3 mach-file.3 mach-map.3 mach-stack.3 \
		mach-swap.3 mach-symbol.3 mach.3 malloc.3 memdraw.3 \
		memlayer.3 mousescrollsize.3 mouse.3 mp.3 muldiv.3 nan.3 \
		notify.3 open.3 pipe.3 plumb.3 postnote.3 prime.3 quote.3 \
		rand.3 rc4.3 read.3 regexp.3 sendfd.3 sysfatal.3 rsa.3 \
		sechash.3 seek.3 setjmp.3 sleep.3 stat.3 strcat.3 \
		string.3 stringsize.3 subfont.3 time.3 wait.3 0intro.3 \
		9p-cmdbuf.3 qball.3 9p-fid.3 9p-file.3 9p-intmap.3 \
		9pclient.3 quaternion.3 readcolmap.3 udpread.3 wctl.3 \
		window.3 searchpath.3 auth.3 authsrv.3 encrypt.3 ndb.3 \
		readcons.3 venti-cache.3 venti-client.3 venti-conn.3 \
		venti-fcall.3 venti-file.3 venti-log.3 venti-mem.3 \
		venti-packet.3 venti-server.3 venti-zero.3 venti.3 \
		acme.3 drawfcall.3

MAN4=		0intro.4 9pserve.4 acme.4 import.4 plumber.4 ramfs.4 \
		vacfs.4 factotum.4 srv.4 9pfuse.4 tapefs.4 smugfs.4

MAN7=		utf.7 regexp.7 0intro.7 color.7 face.7 font.7 image.7 \
		man.7 map.7 ms.7 plot.7 plumb.7 thumbprint.7 ndb.7 \
		keyboard.7 mpictures.7 venti.7 mhtml.7 htmlroff.7
MAN8=		listen1.8 vbackup.8 venti-backup.8 venti-fmt.8 venti.8

MAN9=		0intro.9p attach.9p clunk.9p error.9p flush.9p open.9p \
		openfd.9p read.9p remove.9p stat.9p version.9p walk.9p
MANCOMPRESSED=	no
NOMANCOMPRESS=	yes

EMPTY_DIRS=	plan9/log \
		plan9/bin/lpbin \
		plan9/9pm/Windows/386/bin \
		plan9/9pm/Plan9/386/lib \
		plan9/dist/debian \
		plan9/dist/pkg

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800000
BROKEN=		does not build
.endif

post-patch:
	@${FIND} ${WRKSRC}/man -type f -regex ".*\.[0-9?]$\" \
		| ${XARGS} ${REINPLACE_CMD} -e 's|\\\*9|${PLAN9}|'
	@${REINPLACE_CMD} -e 's|X11=/usr/X11R6|X11=${X11BASE}|' ${WRKSRC}/bin/9l \
		${WRKSRC}/src/cmd/devdraw/mkwsysrules.sh

do-build:
	cd ${WRKSRC} && ./INSTALL

post-build:
	${RM} -rf `${FIND} ${WRKSRC}/dist -type f ! -regex ".*\.png"`
	${RM} -rf `${FIND} ${WRKSRC} -name CVS -o -name .cvsignore`
	( cd ${WRKDIR} && \
	  ${FIND} plan9 -type f \
	    -a ! -path "plan9/man/man[0-9]/*.[0-9]*"; \
	  for D in ${EMPTY_DIRS}; do \
	    ${ECHO_CMD} "@exec ${MKDIR} ${PREFIX}/$${D}"; \
	  done; \
	  ${FIND} plan9 -type d | ${SORT} -r \
		| ${SED} -e 's|^|@dirrm |'; \
	) > ${PLIST}

do-install:
	${CP} -rp ${WRKSRC} ${PREFIX}

post-install:
	cd ${PLAN9} && \
		${SETENV} PLAN9=${PLAN9} PATH=${PATH}:${PLAN9}/bin \
		${SH} lib/moveplan9.sh ${WRKSRC}
	${CHGRP} kmem ${PLAN9}/bin/auxstats
	${CHMOD} +s ${PLAN9}/bin/auxstats
	${CHMOD} 01777 ${PLAN9}/news
	@${ECHO_CMD} ""
	@${CAT} ${PKGMESSAGE}

install-user:
	@${MKDIR} ${HOME}/lib
	${INSTALL_DATA} ${PLAN9}/plumb/initial.plumbing ${HOME}/lib/plumbing

.include <bsd.port.post.mk>
