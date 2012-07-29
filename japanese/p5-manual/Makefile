# New ports collection makefile for:	perl5jman
# Date created:		29 June 1998
# Whom:			SADA Kenji <sada@e-mail.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	man
PORTVERSION=	5.000
CATEGORIES=	japanese perl5
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sada
DISTNAME=	perl${PORTVERSION}${PORTNAME}-j

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl5 Japanese manual

NO_BUILD=	yes
MANPREFIX=	${PREFIX}/man/ja

CAT1=		a2p.1 perl.1 perlapi.1 perlbook.1 perlbot.1 perlcall.1 \
		perldata.1 perldebug.1 perldiag.1 perlembed.1 perlform.1 \
		perlfunc.1 perlguts.1 perlipc.1 perlmod.1 perlobj.1 perlop.1 \
		perlovl.1 perlpod.1 perlre.1 perlref.1 perlrun.1 perlsec.1 \
		perlstyle.1 perlsub.1 perlsyn.1 perltrap.1 perlvar.1 s2p.1
CAT3=		Abbrev.3pm AnyDBMFile.3pm AutoLoader.3pm AutoSplit.3pm \
		Basename.3pm Benchmark.3pm Carp.3pm CheckTree.3pm Collate.3pm \
		Config.3pm Cwd.3pm DB_File.3pm Dynaloader.3pm English.3pm \
		Env.3pm Exporter.3pm Fcntl.3pm FileHandle.3pm Find.3pm \
		Finddepth.3pm GetOptions.3pm Getopt.3pm MakeMaker.3pm \
		Open2.3pm Open3.3pm POSIX.3pm Ping.3pm Socket.3pm \
		integer.3pm less.3pm sigtrap.3pm strict.3pm subs.3pm

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

post-extract:
	@cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		perl5man.tgz ${EXTRACT_AFTER_ARGS}
do-configure:
.for item in 1 3
	@cd ${WRKDIR}/man/japanese/cat${item} && ${GZIP_CMD} ${CAT${item}}
.endfor
do-install:
.for item in 1 3
	@${MKDIR} ${MANPREFIX}/cat${item}
.for file in ${CAT${item}}
	@${INSTALL_MAN} ${WRKDIR}/man/japanese/cat${item}/${file}.gz \
		${MANPREFIX}/cat${item}
.endfor
.endfor

# this is special target which maintainer uses to make port's plist.
plist:
	@${ECHO_CMD} -n >${PLIST}
.for item in 1 3
.for file in ${CAT${item}}
	@${ECHO_CMD} man/ja/cat${item}/${file}.gz >>${PLIST}
.endfor
.endfor

.include <bsd.port.post.mk>
