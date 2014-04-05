# Created by: Niclas Zeising
# $FreeBSD$

PORTNAME=	bsdlibdwarf
PORTVERSION=	0.20110616
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.lysator.liu.se/%SUBDIR%/
MASTER_SITE_SUBDIR=	pub/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BSD licensed implementation of libdwarf

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 1000000
BROKEN=		Does not compile with clang, outdated
.endif

USE_BZIP2=	yes
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	libdwarf*

WRKSRC=		${WRKDIR}/elftoolchain

PLIST_FILES=	lib/libdwarf.so	\
		lib/libdwarf.so.3	\
		lib/libdwarf.a	\
		include/dwarf.h	\
		include/libdwarf.h

MAN3=	dwarf_attr.3					\
	dwarf_attrlist.3				\
	dwarf_attrval_signed.3				\
	dwarf_child.3					\
	dwarf_dealloc.3					\
	dwarf_die_abbrev_code.3				\
	dwarf_diename.3					\
	dwarf_dieoffset.3				\
	dwarf_errmsg.3					\
	dwarf_errno.3					\
	dwarf_expand_frame_instructions.3		\
	dwarf_find_macro_value_start.3			\
	dwarf_finish.3					\
	dwarf_formaddr.3				\
	dwarf_formblock.3				\
	dwarf_formexprloc.3				\
	dwarf_formflag.3				\
	dwarf_formref.3					\
	dwarf_formsig8.3				\
	dwarf_formstring.3				\
	dwarf_formudata.3				\
	dwarf_get_AT_name.3				\
	dwarf_get_abbrev.3				\
	dwarf_get_abbrev_children_flag.3		\
	dwarf_get_abbrev_code.3				\
	dwarf_get_abbrev_entry.3			\
	dwarf_get_abbrev_tag.3				\
	dwarf_get_address_size.3			\
	dwarf_get_arange.3				\
	dwarf_get_aranges.3				\
	dwarf_get_arange_info.3				\
	dwarf_get_cie_index.3				\
	dwarf_get_cie_info.3				\
	dwarf_get_cie_of_fde.3				\
	dwarf_get_cu_die_offset.3			\
	dwarf_get_elf.3					\
	dwarf_get_fde_at_pc.3				\
	dwarf_get_fde_info_for_all_regs.3		\
	dwarf_get_fde_info_for_all_regs3.3		\
	dwarf_get_fde_info_for_cfa_reg3.3		\
	dwarf_get_fde_info_for_reg.3			\
	dwarf_get_fde_info_for_reg3.3			\
	dwarf_get_fde_instr_bytes.3			\
	dwarf_get_fde_list.3				\
	dwarf_get_fde_n.3				\
	dwarf_get_fde_range.3				\
	dwarf_get_funcs.3				\
	dwarf_get_globals.3				\
	dwarf_get_macro_details.3			\
	dwarf_get_pubtypes.3				\
	dwarf_get_ranges.3				\
	dwarf_get_str.3					\
	dwarf_get_types.3				\
	dwarf_get_vars.3				\
	dwarf_get_weaks.3				\
	dwarf_hasattr.3					\
	dwarf_hasform.3					\
	dwarf_highpc.3					\
	dwarf_init.3					\
	dwarf_lineno.3					\
	dwarf_next_cu_header.3				\
	dwarf_seterrarg.3				\
	dwarf_set_frame_cfa_value.3			\
	dwarf_srcfiles.3				\
	dwarf_srclines.3				\
	dwarf_tag.3					\
	dwarf_whatattr.3

MLINKS+=	dwarf_attrval_signed.3	dwarf_attrval_flag.3	\
		dwarf_attrval_signed.3	dwarf_attrval_string.3	\
		dwarf_attrval_signed.3	dwarf_attrval_unsigned.3 \
		dwarf_child.3	dwarf_offdie.3			\
		dwarf_child.3	dwarf_siblingof.3		\
		dwarf_dealloc.3	dwarf_fde_cie_list_dealloc.3	\
		dwarf_dealloc.3	dwarf_funcs_dealloc.3		\
		dwarf_dealloc.3	dwarf_globals_dealloc.3		\
		dwarf_dealloc.3	dwarf_pubtypes_dealloc.3	\
		dwarf_dealloc.3	dwarf_types_dealloc.3		\
		dwarf_dealloc.3	dwarf_vars_dealloc.3		\
		dwarf_dealloc.3	dwarf_weaks_dealloc.3		\
		dwarf_dealloc.3	dwarf_ranges_dealloc.3		\
		dwarf_dealloc.3	dwarf_srclines_dealloc.3	\
		dwarf_init.3	dwarf_elf_init.3		\
		dwarf_dieoffset.3	dwarf_die_CU_offset.3	\
		dwarf_dieoffset.3	dwarf_die_CU_offset_range.3 \
		dwarf_dieoffset.3	dwarf_get_cu_die_offset_given_cu_header_offset.3 \
		dwarf_formref.3	dwarf_global_formref.3		\
		dwarf_formudata.3	dwarf_formsdata.3	\
		dwarf_get_AT_name.3	dwarf_get_ACCESS_name.3	\
		dwarf_get_AT_name.3	dwarf_get_ATE_name.3	\
		dwarf_get_AT_name.3	dwarf_get_CC_name.3	\
		dwarf_get_AT_name.3	dwarf_get_CFA_name.3	\
		dwarf_get_AT_name.3	dwarf_get_CHILDREN_name.3 \
		dwarf_get_AT_name.3	dwarf_get_DS_name.3	\
		dwarf_get_AT_name.3	dwarf_get_DSC_name.3	\
		dwarf_get_AT_name.3	dwarf_get_EH_name.3	\
		dwarf_get_AT_name.3	dwarf_get_END_name.3	\
		dwarf_get_AT_name.3	dwarf_get_FORM_name.3	\
		dwarf_get_AT_name.3	dwarf_get_ID_name.3	\
		dwarf_get_AT_name.3	dwarf_get_INL_name.3	\
		dwarf_get_AT_name.3	dwarf_get_LANG_name.3	\
		dwarf_get_AT_name.3	dwarf_get_LNE_name.3	\
		dwarf_get_AT_name.3	dwarf_get_LNS_name.3	\
		dwarf_get_AT_name.3	dwarf_get_MACINFO_name.3 \
		dwarf_get_AT_name.3	dwarf_get_OP_name.3	\
		dwarf_get_AT_name.3	dwarf_get_ORD_name.3	\
		dwarf_get_AT_name.3	dwarf_get_TAG_name.3	\
		dwarf_get_AT_name.3	dwarf_get_VIRTUALITY_name.3 \
		dwarf_get_AT_name.3	dwarf_get_VIS_name.3	\
		dwarf_get_cu_die_offset.3 dwarf_get_arange_cu_header_offset.3 \
		dwarf_get_fde_list.3	dwarf_get_fde_list_eh.3	\
		dwarf_get_funcs.3	dwarf_func_die_offset.3	\
		dwarf_get_funcs.3	dwarf_func_cu_offset.3	\
		dwarf_get_funcs.3	dwarf_func_name_offsets.3 \
		dwarf_get_funcs.3	dwarf_funcname.3	\
		dwarf_get_globals.3	dwarf_global_die_offset.3 \
		dwarf_get_globals.3	dwarf_global_cu_offset.3 \
		dwarf_get_globals.3	dwarf_global_name_offsets.3 \
		dwarf_get_globals.3	dwarf_globname.3	\
		dwarf_get_pubtypes.3	dwarf_pubtype_die_offset.3 \
		dwarf_get_pubtypes.3	dwarf_pubtype_cu_offset.3 \
		dwarf_get_pubtypes.3	dwarf_pubtype_name_offsets.3 \
		dwarf_get_pubtypes.3	dwarf_pubtypename.3	\
		dwarf_get_ranges.3	dwarf_get_ranges_a.3	\
		dwarf_get_types.3	dwarf_type_die_offset.3	\
		dwarf_get_types.3	dwarf_type_cu_offset.3	\
		dwarf_get_types.3	dwarf_type_name_offsets.3 \
		dwarf_get_types.3	dwarf_typename.3	\
		dwarf_get_vars.3	dwarf_var_die_offset.3	\
		dwarf_get_vars.3	dwarf_var_cu_offset.3	\
		dwarf_get_vars.3	dwarf_var_name_offsets.3 \
		dwarf_get_vars.3	dwarf_varname.3		\
		dwarf_get_weaks.3	dwarf_weak_die_offset.3	\
		dwarf_get_weaks.3	dwarf_weak_cu_offset.3	\
		dwarf_get_weaks.3	dwarf_weak_name_offsets.3 \
		dwarf_get_weaks.3	dwarf_weakname.3	\
		dwarf_hasform.3	dwarf_whatform.3		\
		dwarf_hasform.3	dwarf_whatform_direct.3		\
		dwarf_highpc.3	dwarf_arrayorder.3		\
		dwarf_highpc.3	dwarf_bitoffset.3		\
		dwarf_highpc.3	dwarf_bitsize.3			\
		dwarf_highpc.3	dwarf_bytesize.3		\
		dwarf_highpc.3	dwarf_lowpc.3			\
		dwarf_highpc.3	dwarf_srclang.3			\
		dwarf_lineno.3	dwarf_lineaddr.3		\
		dwarf_lineno.3	dwarf_linebeginstatement.3	\
		dwarf_lineno.3	dwarf_lineblock.3		\
		dwarf_lineno.3	dwarf_lineendsequence.3		\
		dwarf_lineno.3	dwarf_lineoff.3			\
		dwarf_lineno.3	dwarf_linesrc.3			\
		dwarf_lineno.3	dwarf_line_srcfileno.3		\
		dwarf_seterrarg.3	dwarf_seterrhand.3	\
		dwarf_set_frame_cfa_value.3 dwarf_set_frame_rule_initial_value.3 \
		dwarf_set_frame_cfa_value.3 dwarf_set_frame_rule_table_size.3 \
		dwarf_set_frame_cfa_value.3 dwarf_set_frame_same_value.3 \
		dwarf_set_frame_cfa_value.3 dwarf_set_frame_undefined_value.3

NO_STAGE=	yes
do-install:
	${INSTALL_LIB} ${WRKSRC}/libdwarf/libdwarf.so.3 ${PREFIX}/lib/
	${INSTALL_LIB} ${WRKSRC}/libdwarf/libdwarf.a ${PREFIX}/lib/
	(cd ${PREFIX}/lib && ${LN} -s libdwarf.so.3 libdwarf.so)

	${INSTALL_DATA} ${WRKSRC}/libdwarf/dwarf.h ${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/libdwarf/libdwarf.h ${PREFIX}/include/

	for f in ${MAN3}; do \
		${INSTALL_MAN} ${WRKSRC}/libdwarf/$$f ${MANPREFIX}/man/man3/ ; \
	done

.include <bsd.port.post.mk>
