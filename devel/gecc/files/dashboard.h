/* 
 * Group Enabled Cluster Compiler (gecc)
 *
 * Copyright (C) 2002 by Jörg Beyer <j.beyer@web.de>
 *
 * This project was inspired by:
 *   distcc by Martin Pool <mbp@samba.org> http://distcc.samba.org
 *   ccache by Andrew Tridgell (tridge@samba.org)  http://ccache.samba.org
 * please visit their projects also!
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 * USA
 */

/*
 * inspired by the apache dashboard, this implements a monitoring
 * interface to geccd, the server part of gecc.
 *
 */
#ifndef _DASHBOARD_H_
#define _DASHBOARD_H_ 

struct dashb_cache {
	// number of files in cache
	unsigned long file_count;

	// number of cache hits
	unsigned long hit_counter;

	// number of cache misses
	unsigned long miss_counter;
};

const int max_compile_node_id_len=50;

struct dashboard_compile_node {
	char name[max_compile_node_id_len+1];

	// how many files has this special node compiled _for_ _this_ _master_
	unsigned long compiled_files;	
	// and how many source is that in kilo/mega/giga bytes.
	unsigned long compiled_size;	
};

const int dashboard_max_job_text_size=100;

struct dashboard_job
{
	// the comandline (or a part of it)
	char job_text[dashboard_max_job_text_size+1];	
};

const int dashboard_number_of_compile_nodes=20;
const int dashboard_number_of_parallel_compile_jobs=100;

struct geccd_dashboard_memory_layout {
	// make sure that client and server agree about the memory layout.
	int version; 

	// true if cache is on, false otherwise
	bool cache_on;		

	// true if local compilation is on, false otherwise
	bool compile_on;		

	// how many compile jobs are currently running?
	int number_of_current_compile_jobs;
	
	int number_of_compile_nodes;
	struct dashboard_compile_node compile_nodes[dashboard_number_of_compile_nodes]; 	

	int number_of_parallel_compile_jobs;
	struct dashboard_job jobs[dashboard_number_of_parallel_compile_jobs];
};

class Dashboard
{
public:
	Dashboard();
	~Dashboard();

private:
	struct geccd_dashboard_memory_layout memory;

};

#endif
