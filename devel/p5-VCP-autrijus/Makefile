# New ports collection makefile for:	p5-VCP
# Date created:			19 October 2004
# Whom:				autrijus@autrijus.org
#
# $FreeBSD$

PORTNAME=	VCP
PORTVERSION=	0.9.20050110
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/A/AU/AUTRIJUS
PKGNAMEPREFIX=	p5-
PKGNAMESUFFIX=	-autrijus
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-snapshot-${PORTVERSION:C/\.([^.]*)$/-\1/}

MAINTAINER=	autrijus@autrijus.org
COMMENT=	A tool for copying files between various SCM repositories

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${SITE_PERL}/XML/ValidWriter.pm:${PORTSDIR}/textproc/p5-XML-AutoWriter \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/Text/Diff.pm:${PORTSDIR}/textproc/p5-Text-Diff \
		${SITE_PERL}/IPC/Run3.pm:${PORTSDIR}/devel/p5-IPC-Run3 \
		${SITE_PERL}/Pod/Links.pm:${PORTSDIR}/www/p5-PodToHTML \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/Regexp/Shellish.pm:${PORTSDIR}/devel/p5-Regexp-Shellish \
		${SITE_PERL}/BFD.pm:${PORTSDIR}/devel/p5-BFD \
		${SITE_PERL}/Text/Table.pm:${PORTSDIR}/textproc/p5-Text-Table \
		${SITE_PERL}/${PERL_ARCH}/List/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp
RUN_DEPENDS+=	${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp
.endif

PERL_CONFIGURE=	yes

.if ${PERL_LEVEL} < 500600
BROKEN=		"Does not compile with perl ${PERL_VERSION}"
.endif

MAN1=		vcp.1
MAN3=		RevML::Doctype.3 \
		RevML::Writer.3 \
		VCP.3 \
		VCP::Branches.3 \
		VCP::ConfigFileUtils.3 \
		VCP::DB.3 \
		VCP::DB_File.3 \
		VCP::DB_File::big_records.3 \
		VCP::DB_File::sdbm.3 \
		VCP::Debug.3 \
		VCP::DefaultFilters.3 \
		VCP::Dest.3 \
		VCP::Dest::branch_diagram.3 \
		VCP::Dest::csv.3 \
		VCP::Dest::cvs.3 \
		VCP::Dest::data_dump.3 \
		VCP::Dest::metadb.3 \
		VCP::Dest::null.3 \
		VCP::Dest::p4.3 \
		VCP::Dest::perl_data.3 \
		VCP::Dest::revml.3 \
		VCP::Dest::summary.3 \
		VCP::Dest::texttable.3 \
		VCP::Dest::topo_table.3 \
		VCP::Dest::vss.3 \
		VCP::DiffFormat.3 \
		VCP::Driver.3 \
		VCP::FilesDB.3 \
		VCP::Filter.3 \
		VCP::Filter::addlabels.3 \
		VCP::Filter::changesets.3 \
		VCP::Filter::csv_trace.3 \
		VCP::Filter::dumpdata.3 \
		VCP::Filter::identity.3 \
		VCP::Filter::labelmap.3 \
		VCP::Filter::logmemsize.3 \
		VCP::Filter::map.3 \
		VCP::Filter::sort.3 \
		VCP::Filter::stringedit.3 \
		VCP::HeadRevsDB.3 \
		VCP::License.3 \
		VCP::Logger.3 \
		VCP::MainBranchIdDB.3 \
		VCP::Maintenance.3 \
		VCP::Newlines.3 \
		VCP::Patch.3 \
		VCP::Plugin.3 \
		VCP::PodDESCRIPTIONParser.3 \
		VCP::PodOPTIONSParser.3 \
		VCP::Process.3 \
		VCP::RefCountedFile.3 \
		VCP::Rev.3 \
		VCP::RevMapDB.3 \
		VCP::Revs.3 \
		VCP::Source.3 \
		VCP::Source::cvs.3 \
		VCP::Source::metadb.3 \
		VCP::Source::null.3 \
		VCP::Source::p4.3 \
		VCP::Source::revml.3 \
		VCP::Source::vss.3 \
		VCP::TestUtils.3 \
		VCP::UI.3 \
		VCP::UI::Text.3 \
		VCP::UIMachines.3 \
		VCP::Utils.3 \
		VCP::Utils::cvs.3 \
		VCP::Utils::metadb.3 \
		VCP::Utils::p4.3 \
		VCP::Utils::revml.3 \
		VCP::Utils::vss.3

post-patch:
	${FIND} ${WRKSRC} -name "*.orig" -a -exec ${RM} -f {} \;

.include <bsd.port.post.mk>
